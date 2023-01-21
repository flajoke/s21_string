#include "memory.h"



void *s21_memchr(const void* str, int pattern, size_t count) { 
    void *result;
  for(int i = 0; i < count; i++){
      if(*(char *)(str+i) == (char)pattern){
      result = str+i;
    break;
      }
    }
return result;
}
