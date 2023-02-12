#include "s21_string.h"

void *s21_memcpy(void *restrict dst, const void *restrict src, size_t n) {
  signed long int diff = dst - src;
  if ((size_t)diff < (size_t)n) {
    n = diff;
  }
  for (size_t i = 0; i < n; i++) {
    *(unsigned char *)(dst + i) = *(unsigned char *)(src + i);
  }
  return dst;
}
