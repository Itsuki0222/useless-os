#include "memory.c"
#include "types.h"

#pragma once

__attribute__((no_builtin("memset")))
void *memset(void *b, u32 c, size_t len) {
    u8 *p = b;
    while(len > 0) {
        *p = (u8)c;
        p++;
        len--;
    }
    return b;
}
