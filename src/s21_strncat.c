#include "s21_string.h"

// Добавляет строку, на которую указывает src, в конец строки, 
// на которую указывает dest, длиной до n символов.

char *s21_strncat(char *dest, const char *src, size_t n) {
    char *tmp = dest + s21_strlen(dest);

    while (*src != '\0' && n--) {
        *tmp++ = *src++;
    }

    *tmp = '\0';

    return dest;
}
