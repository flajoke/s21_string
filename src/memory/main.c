#include "memory.h"

int main () {
   char str[] = "http://www.tutorialspoint.com";
   const char ch = '.';
   char *ret;

   ret = s21_memchr(str, ch, strlen(str));

   printf("String after |%c| is - |%s|\n", ch, ret);

   return(0);
}
