#include "string.h"

void *s21_to_lower(const char *str) {
    char *str_copy = NULL;

    if (str != NULL) {
        size_t len = s21_strlen(str);

        str_copy = (char *)malloc(sizeof(char) * (len + 1));

        if (str_copy) {
            for (size_t i = 0; i <= len; i++) {
                if (str[i] >= 'A' && str[i] <= 'Z') {
                    str_copy[i] = (str[i] - 'A') + 'a';
                } else {
                    str_copy[i] = str[i];
                }
            }
            str_copy[len] = '\0';
        }
    }

    return str_copy;
}

