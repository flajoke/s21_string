#include "s21_string.h"
#include <string.h>


// Возвращает новую строку, в которой удаляются все начальные
// и конечные вхождения набора заданных символов (trim_chars)
// из данной строки (src). В случае какой-либо 
// ошибки следует вернуть значение NULL

// void* s21_trim(const char* src, const char* trim_chars) {
//     char* res = NULL;
//     if (src && trim_chars) {
//         char* ptr_str = (char*)src;
//         char* end_str = (char*)src + s21_strlen(src);
//         for (; *ptr_str && s21_strchr(trim_chars, *ptr_str); ptr_str++) ;
//         for (; end_str != ptr_str && s21_strchr(trim_chars, *(end_str - 1)); end_str--) ;
//         res = (char*)malloc((end_str - ptr_str + 1) * sizeof(char));
//         if (res) {
//             s21_strncpy(res, ptr_str, end_str - ptr_str);
//             *(res + (end_str - ptr_str)) = '\0';
//         }
//     }
//     return res;
// }

// void *s21_trim(const char *src, const char *trim_chars) {
//   if (!src || !trim_chars) {
//     return NULL;
//   }

//   int start = 0, end = strlen(src) - 1;
//   while (start <= end && strchr(trim_chars, src[start])) {
//     start++;
//   }
//   while (end >= start && strchr(trim_chars, src[end])) {
//     end--;
//   }

//   int length = end - start + 1;
//   if (length <= 0) {
//     length = 1;
//   }

//   char *trimmed = malloc(length + 1);
//   if (!trimmed) {
//     return NULL;
//   }

//   memcpy(trimmed, src + start, length);
//   trimmed[length] = '\0';

//   return trimmed;
// }

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
