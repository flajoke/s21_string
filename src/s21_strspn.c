#include "s21_string.h"

size_t s21_strspn(const char *s, const char *charset) {
  size_t count = 0;
  char match = 0;
  for (size_t i = 0; s[i] != '\0'; i++) {
    for (size_t j = 0; charset[j] != '\0'; j++) {
      if (s[i] == charset[j]) {
        match = 1;
      }
      if (match) {
        count++;
        match = 0;
      }
    }
  }
  return count;
}