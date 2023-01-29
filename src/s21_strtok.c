#include "s21_string.h"

// Разбивает строку str на ряд токенов, разделенных delim.

char *s21_strtok(char *str, const char *delim) {
  static char *result = NULL;
  if (str) {
    result = str;
    while (*result && s21_strchr(delim, *result))
      *result++ = '\0';
  }
  if (result != NULL) {
    if (*result != '\0') {
      str = result;
      while (*result && !s21_strchr(delim, *result))
        ++result;
      while (*result && s21_strchr(delim, *result))
        *result++ = '\0';
      } else {
        str = NULL;
      }
    } else {
    str = NULL;
  }
  return str;
}
