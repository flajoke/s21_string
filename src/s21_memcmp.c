#include "s21_string.h"

int s21_memcmp(const void *s1, const void *s2, size_t n) {
  size_t result = 0;
  for (size_t i = 0; i < n; i++) {
    result = *(unsigned char *)(s1 + i) - *(unsigned char *)(s2 + i);
    if (result != 0) {
      break;
    }
  }
  return result;
}
