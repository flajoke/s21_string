#include "s21_string.h"

int s21_strcmp(const char *str1, const char *str2) {
    unsigned char *s1 = (unsigned char *)str1;
    unsigned char *s2 = (unsigned char *)str2;
    int res = 1;
    while (*s1 == *s2) {
        if (*s1 == '\0') {
            res = 0;
            break;
        }
        ++s1;
        ++s2;
    }
    if (res != 0) {
        res = *s1 - *s2;
    }
    return res;
}
