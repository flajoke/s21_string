#include <string.h>

// Разбивает строку str на ряд токенов, разделенных delim.

char* s21_strtok(char* str, const char* delim) {
    static char* p = NULL;
    if (str) {
        p = str;
    } else if (!p) {
        return NULL;
    }
    char* start = p;
    while (*p) {
        for (int i = 0; delim[i]; i++) {
            if (*p == delim[i]) {
                *p = '\0';
                p++;
                return start;
            }
        }
        p++;
    }
    return start;
}
