#include "s21_string.h"

// Добавляет строку, на которую указывает src, в конец строки, 
// на которую указывает dest. 

char *strcat(char *dest, const char *src){
    char *res;
    char *tmp = dest;
    while (*tmp != '\0') {
        tmp++;
    }
    while (*src != '\0') {
        *tmp++ = *src++;
    }
    *tmp = '\0';
    res = dest;
    return res;
}		
