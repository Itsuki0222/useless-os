#include "limine.h"
#include "types.h"
#include "unifont.h"
#include "console.h"

extern volatile const struct limine_framebuffer_request fb_req;

struct limine_framebuffer *fb;
u32 *fb_ptr;

void init_graphics(void) {
    fb = fb_req.response->framebuffers[0];
    fb_ptr = fb->address;
}


static inline void draw_char(u32 pixels_per_line, u32 color, u8 c, u32 x, u32 y) {
    u32 *dest = fb_ptr + (y * pixels_per_line) + x;
    for (u32 l = 0; l < 16; l++) {
        uint8_t byte = unifont[c][l];

        for (u32 col = 0; col < 8; col++) {
            if ((byte << col) & 0x80) {
                dest[col] = color;
            } else {
                dest[col] = 0x00000000;
            }
        }
        dest += pixels_per_line;
    }
}


void fill_screen(u8 r, u8 g, u8 b) {
    uint32_t color = (r << fb->red_mask_shift) |
    (g << fb->green_mask_shift) |
    (b << fb->blue_mask_shift);

    for (uint32_t y = 0; y < fb->height; y++) {
        uint32_t *row = (uint32_t *)((uintptr_t)fb_ptr + (y * fb->pitch));
        for (uint32_t x = 0; x < fb->width; x++) {
            row[x] = color;
        }
    }
}


void printstr(const u8 *str) {
    u32 pixels_per_line = fb->pitch / 4;
    u32 x = 0;
    while (*str != 0) {
        draw_char(pixels_per_line, 0xFFFFFF, *str, x, 0);
        x += 8;
        str++;
    }
}
