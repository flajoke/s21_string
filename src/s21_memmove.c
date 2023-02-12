#include "s21_string.h"


void *s21_memmove(void *dst, const void *src, size_t len) {
  unsigned char buffer[len];
  for (size_t i = 0; i < len; i++) {
    buffer[i] = *(unsigned char *)(src + i);
  }

  for (size_t i = 0; i < len; i++) {
    *(unsigned char *)(dst + i) = buffer[i];
  }
  return dst;
}
