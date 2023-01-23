#include "s21_string.h"

// Выполняет поиск последнего вхождения символа c (беззнаковый тип)
// в строке, на которую указывает аргумент str.

char *s21_strrchr(const char *str, int c) {
    const char *res = NULL;
    if (str != NULL) {
        while(*str != '\0') {
            if (*str == (char)c) {
                res = str;
            }
	    str++;
        }
    }
    return (char *)res;
}
