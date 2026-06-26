#include "limine.h"
#include "types.h"
#include "unifont.h"

#pragma once

extern struct limine_framebuffer *fb;
extern uint32_t *fb_ptr;

void init_graphics(void);
void fill_screen(u8 r, u8 g, u8 b);
void printstr(const u8 *str);
