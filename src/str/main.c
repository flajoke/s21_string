#include "stre.h"

int main() {
  
    int size;
  
    // initializing strings
    char str1[] = "abcd";
    char str2[] = "";
  
    // using strcspn() to calculate initial chars
    // before 1st matching chars.
    // returns 3
    size = s21_strcspn(str1, str2);
  
    printf("The unmatched characters before first matched character :  %d\n", size);

  return 0;
}
