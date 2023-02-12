#include "s21_string.h"
#include <string.h>


// Возвращает новую строку, в которой удаляются все начальные
// и конечные вхождения набора заданных символов (trim_chars)
// из данной строки (src). В случае какой-либо 
// ошибки следует вернуть значение NULL

void *s21_trim(const char *src, const char *trim_chars) {
    char *res = NULL;

    if (src) {
        if (trim_chars && *trim_chars) {
            size_t len = s21_strlen(src);
            size_t chars_len = s21_strlen(trim_chars);

            s21_trim_left(&src, trim_chars, &len, chars_len);
            if (len)
                s21_trim_right(&src, trim_chars, &len, chars_len);

            res = (char *)malloc(sizeof(char) * (len + 1));

            if (res) {
                for (size_t i = 0; i < len + 1; i++) {
                    if (i < len) {
                        res[i] = src[i];
                    } else {
                        res[i] = '\0';
                    }
                }
            }
        } else {
            res = s21_trim(src, " \t\n");
        }
    }

    return res;
}

void s21_trim_left(const char **src, const char *trim_chars,
                   size_t *src_len, const size_t trim_chars_len) {
    size_t m = 0;

    while (src && m != trim_chars_len) {
        if ((**src) == trim_chars[m]) {
            (*src)++;
            (*src_len) -= 1;
            m = 0;
            continue;
        }
        m++;
    }
}

void s21_trim_right(const char **src, const char *trim_chars,
                    size_t *src_len, const size_t trim_chars_len) {
    size_t m = 0;
    size_t i = (*src_len) - 1;

    while (src && m != trim_chars_len) {
        if ((*src)[i] == trim_chars[m]) {
            i--;
            (*src_len)--;
            m = 0;
            continue;
        }

        m++;
    }
}
