#include "memory.h"

void *s21_memset(void *b, int c, size_t len) {
  for (int i = 0; i < len; i++) {
    *(unsigned char *)(b + i) = (unsigned char)c;
  }
  return (unsigned char *)b;
}
