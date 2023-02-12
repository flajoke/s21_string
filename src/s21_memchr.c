#include "s21_string.h"

void *s21_memchr(const void *str, int pattern, size_t count) {
  int result = -1;
  for (size_t i = 0; i < count; i++) {
    if (*(unsigned char *)(str + i) == (unsigned char)pattern) {
      result = i;
      break;
    }
  }
  return (result == -1 ? NULL : (unsigned char *)(str + result));
}
