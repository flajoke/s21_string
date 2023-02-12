#include "s21_string.h"


void *s21_memset(void *b, int c, size_t len) {
  for (size_t i = 0; i < len; i++) {
    *(unsigned char *)(b + i) = (unsigned char)c;
  }
  return (unsigned char *)b;
}
