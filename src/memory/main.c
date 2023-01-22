#include "memory.h"

int main() {
  char str1[24] = ".ooooooooooooooooooooooo";
  char str2[] = ".ooooooooooooooooooooooo";

  puts("str1 before memcpy ");
  puts(str1);

  /* Copies contents of str2 to str1 */
  memcpy(str1 + 2, str1, 24 - 2);

  puts("\nstr1 after memcpy ");
  puts(str1);

  s21_memcpy(str1 + 2, str1, 24 - 2);

  puts("\nstr1 after s21_memcpy ");
  puts(str1);

  return 0;
}
