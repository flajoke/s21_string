#include "s21_string.h"

// Выполняет поиск первого вхождения символа c (беззнаковый тип) в строке,
// на которую указывает аргумент str.

char *s21_strchr(const char *str, int c) {
    const char *res = NULL;	
    if (str != NULL) {
	while(*(str - 1) != '\0') {
    	    if (*str == (char) c) {
		res = str;
		break;
            }
	    str++;
	}
    }
    return (char *)res;
}
