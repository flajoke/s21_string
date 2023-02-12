#include "s21_string.h"

size_t s21_strlen(const char *str) {
    size_t len = 0;

    if (str) {
        for (int i = 0; str[i]; i++) {
            len++;
        }
    }

    return len;
}

