#include "s21_string.h"

void *s21_memchr(const void* str, int c, size_t n) { 
    void *result = NULL;
    for (int i = 0; i < n; i++) {
        if (*(unsigned char *) str + i == c) {
            *(unsigned char *) result = *(unsigned char *) str + i;
        }
    }

    return result;
}
