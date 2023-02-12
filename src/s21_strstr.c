#include "s21_string.h"

char* s21_strstr(const char* haystack, const char* needle) {
    int i, j;
    int needle_len = s21_strlen(needle);
    int haystack_len = s21_strlen(haystack);
    for (i = 0; i <= haystack_len - needle_len; i++) {
        for (j = 0; j < needle_len; j++) {
            if (haystack[i + j] != needle[j]) {
                break;
            }
        }
        if (j == needle_len) {
            return (char*) haystack + i;
        }
    }
    return NULL;
}
