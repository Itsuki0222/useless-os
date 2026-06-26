#include <stdint.h>
#include "limine.h"
#include "unifont.h"
#include "string.h"
#include "types.h"
#include "console.h"

__attribute__((used, section(".limine_requests")))
static volatile uint64_t limine_base_revision[] = LIMINE_BASE_REVISION(6);

__attribute__((used, section(".limine_requests")))
volatile struct limine_framebuffer_request fb_req = {
    .id = LIMINE_FRAMEBUFFER_REQUEST_ID,
    .revision = 0
};

__attribute__((used, section(".limine_requests_start")))
static volatile uint64_t limine_requests_start_marker[] = LIMINE_REQUESTS_START_MARKER;

__attribute__((used, section(".limine_requests_end")))
static volatile uint64_t limine_requests_end_marker[] = LIMINE_REQUESTS_END_MARKER;

void halt(void) {
    for (;;) __asm__("hlt");
}

void kernel_main(void) {
    if (LIMINE_BASE_REVISION_SUPPORTED(limine_base_revision) == false) {
        halt();
    }

    if (fb_req.response == NULL
        || fb_req.response->framebuffer_count < 1) {
        halt();
    }

    init_graphics();
    fill_screen(0, 0, 0);
    printstr("Hello, World!");


    halt();
}
