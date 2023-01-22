#include "memory.h"

int s21_memcmp(const void *s1, const void *s2, size_t n) {
  int result = 0;
  for (int i = 0; i < n; i++) {
    result = *(unsigned char *)(s1 + i) - *(unsigned char *)(s2 + i);
    if (result != 0) {
      break;
    }
  }
  return result;
}
