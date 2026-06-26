OUTPUT_FORMAT("elf64-x86-64")
OUTPUT_ARCH(i386:x86-64)
ENTRY(kernel_main)

KERNEL_VMA = 0xFFFFFFFF80000000;

PHDRS {
    text   PT_LOAD FLAGS(5);
    rodata PT_LOAD FLAGS(4);
    data   PT_LOAD FLAGS(6);
}

SECTIONS {
    . = KERNEL_VMA;

    .text ALIGN(CONSTANT(MAXPAGESIZE)) : AT(ADDR(.text) - KERNEL_VMA) {
        *(.text .text.*)
    } :text

    .rodata ALIGN(CONSTANT(MAXPAGESIZE)) : AT(ADDR(.rodata) - KERNEL_VMA) {
        *(.rodata .rodata.*)
    } :rodata

    .limine_requests_start ALIGN(CONSTANT(MAXPAGESIZE)) : AT(ADDR(.limine_requests_start) - KERNEL_VMA) {
        KEEP(*(.limine_requests_start))
    } :data

    .limine_requests ALIGN(8) : AT(ADDR(.limine_requests) - KERNEL_VMA) {
        KEEP(*(.limine_requests))
    } :data

    .limine_requests_end ALIGN(8) : AT(ADDR(.limine_requests_end) - KERNEL_VMA) {
        KEEP(*(.limine_requests_end))
    } :data

    .data ALIGN(CONSTANT(MAXPAGESIZE)) : AT(ADDR(.data) - KERNEL_VMA) {
        *(.data .data.*)
    } :data

    .bss ALIGN(16) : AT(ADDR(.bss) - KERNEL_VMA) {
        *(COMMON)
        *(.bss .bss.*)
    } :data

    /DISCARD/ : { *(.eh_frame) *(.note .note.*) }
}
