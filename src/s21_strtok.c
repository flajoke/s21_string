#include <string.h>

char* s21_strtok(char* str, const char* delim) {
    static char* last_token = NULL;
    if (str == NULL) {
        str = last_token;
    }
    if (str == NULL) {
        return NULL;
    }
    char* token_start = str;
    char* token_end = str;
    while (*token_start != '\0') {
        for (int i = 0; delim[i] != '\0'; i++) {
            if (*token_start == delim[i]) {
                token_start++;
                token_end = token_start;
                break;
            }
        }
        if (*token_end == '\0') {
            last_token = token_end;
            return token_start;
        }
        while (*token_end != '\0') {
            for (int i = 0; delim[i] != '\0'; i++) {
                if (*token_end == delim[i]) {
                    *token_end = '\0';
                    last_token = token_end + 1;
                    return token_start;
                }
            }
            token_end++;
        }
    }
    last_token = token_end;
    return token_start;
}
