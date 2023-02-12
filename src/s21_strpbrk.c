#include "s21_string.h"

// char *s21_strpbrk(const char *s, const char *charset) {
//   size_t i;
//   char match = 0;
//   for (i = 0; s[i] != '\0'; i++) {
//     for (size_t j = 0; charset[j] != '\0'; j++) {
//       if (s[i] == charset[j]) {
//         match = 1;
//         break;
//       }
//     }
//     if (match) {
//       break;
//     }
//   }
//   return (char *)(s + i);
// }

char *s21_strpbrk(const char *str1, const char *str2) {
    const char *s1, *s2;
    for (s1 = str1; *s1 != '\0'; s1++) {
        for (s2 = str2; *s2 != '\0'; s2++) {
            if (*s1 == *s2) {
                return (char *)s1;
            }
        }
    }
    return NULL;
}
