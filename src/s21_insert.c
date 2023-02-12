#include "s21_string.h"

// Возвращает новую строку, в которой указанная строка (str) 
// вставлена в указанную позицию (start_index)
// в данной строке (src). В случае какой-либо ошибки 
// следует вернуть значение NULL

void *s21_insert(const char *src, const char *str, size_t start_index) {
    char *res = NULL;

    if (src != NULL && str != NULL ) {
        size_t src_len = s21_strlen(src);
        size_t str_len = s21_strlen(str);
        size_t new_len = src_len + str_len;

        res = calloc(new_len + 1, sizeof(char));

        if (res) {
            for (size_t i = 0, j = 0, m = 0; i < new_len; i++) {
                if (i < start_index || !str[m])
                    res[i] = src[j++];
                else
                    res[i] = str[m++];
            }
            res[new_len] = '\0';
        }
    } else if (str == NULL && src != NULL) {
        res = calloc(s21_strlen(src) + 1, sizeof(char));
        s21_strcpy(res, src);
    }
    return res;
}
