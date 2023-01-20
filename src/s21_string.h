#ifndef _S21_STRING_H_
#define _S21_STRING_H_

#if !defined (__SIZE_TYPE__)
    #define __SIZE_TYPE__ long unsigned int;
#endif
#if !(defined(__GNUG__) && defined (size_t))
    typedef __SIZE_TYPE__ size_t;
#endif

#if !defined (NULL)
#	define NULL ((void *)0)
#endif 

void *s21_memchr(const void *str, int c, size_t n);
int s21_memcmp(const void *str1, const void *str2, size_t n);
void *s21_memcpy(const void *dest, const void *src, size_t n);
void *s21_memmove(const void *dest, const void *src, size_t n);
void *s21_memset(const void *str, int c, size_t n);

char *s21_strcat(char *dest, const char *src);
char *s21_strncat(char *dest, const char *src, size_t n);
char *s21_strchr(const char *str, int c);
int s21_strcmp(const char *str1, const char *str2);
int s21_strncmp(const char *str1, const char *str2, size_t n);
char *s21_strcpy(char *dest, const char *src);
char *s21_strncpy(char *dest, const char *src, size_t n);
size_t s21_strcspn(const char *str1, const char *str2);
char *s21_strerror(int errnum);
size_t s21_strlen(const char *str);
char *s21_strpbrk(const char *str1, const char *str2);
char *s21_strrchr(const char *str, int c);
size_t s21_strspn(const char *str1, const char *str2);
char *s21_strstr(const char *haystack, const char *needle);
char *s21_strtok(char *str, const char *delim);

// NOTE(pottluci): they return NEW allocated string;
//                  v
void *s21_to_upper(const char *str);
void *s21_to_lower(const char *str);
void *s21_insert(const char *src, const char *str, size_t start_index);
void *s21_trim(const char *str, const char *trim_chars);


#endif // _S21_STRING_H_
