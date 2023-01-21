#include "s21_string.h"

// Сравнивает не более первых n байтов str1 и str2.

int s21_strncmp(const char *str1, const char *str2, size_t n) {
    int flag = 0;
    while (n--) {
        if (*str1 != *str2) {
            flag = *str1 - *str2;
        } else {
            ++str1;
            ++str2;
        }
    }
    return flag;
}
