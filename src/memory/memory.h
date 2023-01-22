#ifndef S21_MEMORY
#define S21_MEMORY

#include <stdio.h>
#include <stdlib.h>

void *s21_memchr(const void *str, int pattern, size_t count);
int s21_memcmp(const void *s1, const void *s2, size_t n);
void *s21_memset(void *b, int c, size_t len);
void *s21_memmove(void *dst, const void *src, size_t len);
void *s21_memcpy(void *restrict dst, const void *restrict src, size_t n);


#include <string.h>

#endif  // S21_MEMORY
