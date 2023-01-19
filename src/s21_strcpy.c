#include "s21_string.h"

char *s21_strcpy(char *dest, const char *src) {
    char *flag;
    int i = 0;
    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    flag = dest;
    return flag;
}
