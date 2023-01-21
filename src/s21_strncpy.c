// Копирует до n символов из строки, на которую указывает src, в dest.

#include "s21_string.h"

char *s21_strncpy(char *dest, const char *src, size_t n) {
    size_t i;
    for (i = 0; i < n && src[i] != '\0'; i++) {
        dest[i] = src[i];
    }
    while (i < n) {
        dest[i] = '\0';
        i++;
    }
    return dest;
}
