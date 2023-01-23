#include "s21_string.h"

// Выполняет поиск первого вхождения символа c (беззнаковый тип) в строке,
// на которую указывает аргумент str.

char *s21_strchr(const char *str, int c) {
    const char *res = NULL;	
    if (str != NULL) {
	do {
    	    if (*str == (char) c) {
		res = str;
		break;
            }
	    str++;
	} while(str[-1] != '\0'); 
    }
    return (char *)res;
}
