#include "stre.h"

char *s21_strpbrk(const char *s, const char *charset) {
  size_t i;
  char match = 0;
  for (i = 0; s[i] != '\0'; i++) {
    for (size_t j = 0; charset[j] != '\0'; j++) {
      if (s[i] == charset[j]) {
        match = 1;
        break;
      }
    }
    if (match) {
      break;
    }
  }
  return (char *)(s + i);
}