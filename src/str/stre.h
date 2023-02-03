#ifndef S21_MEMORY
#define S21_MEMORY

#include <stdio.h>
#include <stdlib.h>

size_t s21_strspn(const char *s, const char *charset);
size_t s21_strcspn(const char *s, const char *charset);
char *s21_strpbrk(const char *s, const char *charset);

#include <string.h>

#endif  // S21_MEMORY
