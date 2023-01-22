#include <check.h>
#include <errno.h>
#include <string.h>

#include "s21_string.h"

#define TESTS_COUNT 8

#if 0
#undef _ck_assert_mem
#define _ck_assert_mem(X, OP, Y, L)                                            \
  do {                                                                         \
    const uint8_t* _ck_x = (const uint8_t*)(X);                                \
    const uint8_t* _ck_y = (const uint8_t*)(Y);                                \
    size_t _ck_l = (L);                                                        \
    char _ck_x_str[CK_MAX_ASSERT_MEM_PRINT_SIZE * 2 + 1];                      \
    char _ck_y_str[CK_MAX_ASSERT_MEM_PRINT_SIZE * 2 + 1];                      \
    static const char _ck_hexdigits[] = "0123456789abcdef";                    \
    size_t _ck_i;                                                              \
    size_t _ck_maxl = (_ck_l > CK_MAX_ASSERT_MEM_PRINT_SIZE)                   \
                          ? CK_MAX_ASSERT_MEM_PRINT_SIZE                       \
                          : _ck_l;                                             \
    for (_ck_i = 0; _ck_i < _ck_maxl; _ck_i++) {                               \
      _ck_x_str[_ck_i * 2] = _ck_hexdigits[(_ck_x[_ck_i] >> 4) & 0xF];         \
      _ck_y_str[_ck_i * 2] = _ck_hexdigits[(_ck_y[_ck_i] >> 4) & 0xF];         \
      _ck_x_str[_ck_i * 2 + 1] = _ck_hexdigits[_ck_x[_ck_i] & 0xF];            \
      _ck_y_str[_ck_i * 2 + 1] = _ck_hexdigits[_ck_y[_ck_i] & 0xF];            \
    }                                                                          \
    _ck_x_str[_ck_i * 2] = 0;                                                  \
    _ck_y_str[_ck_i * 2] = 0;                                                  \
    if (_ck_maxl != _ck_l) {                                                   \
      _ck_x_str[_ck_i * 2 - 2] = '.';                                          \
      _ck_y_str[_ck_i * 2 - 2] = '.';                                          \
      _ck_x_str[_ck_i * 2 - 1] = '.';                                          \
      _ck_y_str[_ck_i * 2 - 1] = '.';                                          \
    }                                                                          \
    ck_assert_msg(0 OP memcmp(_ck_y, _ck_x, _ck_l),                            \
                  "[1;33mAssertion[0m [33m'%s'[0m failed:\n[\n\t[32m "    \
                  "std: [1;32m\"%s\"[0m\n\t[31m s21: [1;31m\"%s\"[0m\n]", \
                  #X, _ck_x_str, _ck_y_str);                                   \
  } while (0)
#else
#undef _ck_assert_mem
#define _ck_assert_mem(X, OP, Y, L)                                            \
  do {                                                                         \
    const uint8_t* _ck_x = (const uint8_t*)(X);                                \
    const uint8_t* _ck_y = (const uint8_t*)(Y);                                \
    size_t _ck_l = (L);                                                        \
    char _ck_x_str[CK_MAX_ASSERT_MEM_PRINT_SIZE * 2 + 1];                      \
    char _ck_y_str[CK_MAX_ASSERT_MEM_PRINT_SIZE * 2 + 1];                      \
    size_t _ck_i;                                                              \
    size_t _ck_maxl = (_ck_l > CK_MAX_ASSERT_MEM_PRINT_SIZE)                   \
                          ? CK_MAX_ASSERT_MEM_PRINT_SIZE                       \
                          : _ck_l;                                             \
    for (_ck_i = 0; _ck_i < _ck_maxl; _ck_i++) {                               \
      _ck_x_str[_ck_i] = _ck_x[_ck_i];                                         \
      _ck_y_str[_ck_i] = _ck_y[_ck_i];                                         \
    }                                                                          \
    _ck_x_str[_ck_i] = 0;                                                      \
    _ck_y_str[_ck_i] = 0;                                                      \
    ck_assert_msg(0 OP memcmp(_ck_y, _ck_x, _ck_l),                            \
                  "[1;33mAssertion[0m [33m'%s'[0m failed:\n[\n\t[32m "    \
                  "std: [1;32m\"%s\"[0m\n\t[31m s21: [1;31m\"%s\"[0m\n]", \
                  #X, _ck_x_str, _ck_y_str);                                   \
  } while (0)
#endif

#undef _ck_assert_str
#define _ck_assert_str(X, OP, Y, NULLEQ, NULLNE)                             \
  do {                                                                       \
    const char* _ck_x = (X);                                                 \
    const char* _ck_y = (Y);                                                 \
    const char* _ck_x_s;                                                     \
    const char* _ck_y_s;                                                     \
    const char* _ck_x_q;                                                     \
    const char* _ck_y_q;                                                     \
    if (_ck_x != NULL) {                                                     \
      _ck_x_q = "\"";                                                        \
      _ck_x_s = _ck_x;                                                       \
    } else {                                                                 \
      _ck_x_q = "";                                                          \
      _ck_x_s = "(null)";                                                    \
    }                                                                        \
    if (_ck_y != NULL) {                                                     \
      _ck_y_q = "\"";                                                        \
      _ck_y_s = _ck_y;                                                       \
    } else {                                                                 \
      _ck_y_q = "";                                                          \
      _ck_y_s = "(null)";                                                    \
    }                                                                        \
    ck_assert_msg((NULLEQ && (_ck_x == NULL) && (_ck_y == NULL)) ||          \
                      (NULLNE && ((_ck_x == NULL) || (_ck_y == NULL)) &&     \
                       (_ck_x != _ck_y)) ||                                  \
                      ((_ck_x != NULL) && (_ck_y != NULL) &&                 \
                       (0 OP strcmp(_ck_y, _ck_x))),                         \
                  "[1;33mAssertion [0m [33m'%s'[0m failed:\n[\n\t[32m " \
                  "std: == %s%s%s[0m\n\t[31m s21: == %s%s%s[0m\n]",       \
                  #X, _ck_x_q, _ck_x_s, _ck_x_q, _ck_y_q, _ck_y_s, _ck_y_q); \
  } while (0)

#define CHECK(func)                                                          \
  do {                                                                       \
    TYPE std = func;                                                         \
    TYPE s21 = s21_##func;                                                   \
    ck_assert_msg(                                                           \
        std == s21,                                                          \
        "[1;33mAssertion[0m [33m'%s'[0m failed:\n[\n\t[32m std: " FTYPE \
        "[0m\n\t[31m s21: " FTYPE "[0m\n]",                               \
        #func, std, s21);                                                    \
  } while (0)

enum test_specific_value {
  SIZE = 24,
  HALF = SIZE / 2,
};

/*
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */

#if 1
#define FTYPE "%p"
#define TYPE void*
START_TEST(MEMCHR) {
  const char haystack[SIZE] = "........o...........x..";

  CHECK(memchr(haystack, 'o', HALF));

  CHECK(memchr(haystack, 'x', HALF));
  CHECK(memchr(haystack, 'x', SIZE));
}
END_TEST
#undef FTYPE
#undef TYPE
#endif

#if 1
#define FTYPE "%d"
#define TYPE int
START_TEST(MEMCMP) {
  const char string[SIZE] = "............oooooooooooo";
  const char other[SIZE] = "............oooooooooooo";

  CHECK(memcmp(string, string, HALF));
  CHECK(memcmp(string, &string[HALF - 1], HALF));
  CHECK(memcmp(string, string, SIZE));

  CHECK(memcmp(string, other, HALF));
  CHECK(memcmp(string, &other[HALF - 1], HALF));

  CHECK(memcmp(string, string, 0));
}
END_TEST
#undef FTYPE
#undef TYPE
#endif

#if 1
#define FTYPE "%p"
#define TYPE void*
START_TEST(MEMCPY) {
  {
    char src[SIZE] = "oooooooooooooooooooooooo";
    char dest[SIZE] = "........................";

    s21_memcpy(dest, src, SIZE);
    ck_assert_mem_eq(dest, src, SIZE);
  }

  {
    char src[SIZE] = "oooooooooooooooooooooooo";
    char dest[SIZE] = "........................";

    CHECK(memcpy(dest, src, SIZE));
  }

  {
    char s21[SIZE] = ".ooooooooooooooooooooooo";
    char std[SIZE] = ".ooooooooooooooooooooooo";

    s21_memcpy(s21 + 1, s21, SIZE - 1);
    memcpy(std + 1, std, SIZE - 1);

    // NOTE(pottluci): "..oooooooooooooooooooo???"
    ck_assert_mem_eq(std, s21, SIZE);
  }

  {
    char s21[SIZE] = ".xxxxxxxxxxxxxxxxxxxxxxx";
    char std[SIZE] = ".xxxxxxxxxxxxxxxxxxxxxxx";

    s21_memcpy(s21, s21 + 1, SIZE - 1);
    memcpy(std, std + 1, SIZE - 1);

    // NOTE(pottluci): "xxxxxxxxxxxxxxxxxxxxxxxx"
    ck_assert_mem_eq(std, s21, SIZE);
  }
}
END_TEST
#undef FTYPE
#undef TYPE
#endif

#if 1
#define FTYPE "%p"
#define TYPE void*
START_TEST(MEMMOVE) {
  {
    char src[SIZE] = "oooooooooooooooooooooooo";
    char dest[SIZE] = "........................";

    s21_memmove(dest, src, SIZE);
    ck_assert_mem_eq(dest, src, SIZE);
  }

  {
    char src[SIZE] = "oooooooooooooooooooooooo";
    char dest[SIZE] = "........................";

    CHECK(memmove(dest, src, SIZE));
  }

  {
    char s21[SIZE] = ".ooooooooooooooooooooooo";
    char std[SIZE] = ".ooooooooooooooooooooooo";

    s21_memmove(s21 + 1, s21, SIZE - 1);
    memmove(std + 1, std, SIZE - 1);

    // NOTE(pottluci): ".ooooooooooooooooooooooo"
    ck_assert_mem_eq(std, s21, SIZE);
  }

  {
    char s21[SIZE] = ".xxxxxxxxxxxxxxxxxxxxxxx";
    char std[SIZE] = ".xxxxxxxxxxxxxxxxxxxxxxx";

    s21_memmove(s21, s21 + 1, SIZE - 1);
    memmove(std, std + 1, SIZE - 1);

    // NOTE(pottluci): ".xxxxxxxxxxxxxxxxxxxxxxx"
    ck_assert_mem_eq(std, s21, SIZE);
  }
}
END_TEST
#undef FTYPE
#undef TYPE
#endif

#if 1
#define FTYPE "%p"
#define TYPE void*
START_TEST(MEMSET) {
  char s21[SIZE] = "........................";
  char std[SIZE] = "........................";

  s21_memset(s21, 'o', SIZE);
  memset(std, 'o', SIZE);

  ck_assert_mem_eq(s21, std, SIZE);

  char src[SIZE] = "........................";
  CHECK(memset(src, 'o', SIZE));
}
END_TEST
#undef FTYPE
#undef TYPE
#endif

#if 0
#define FTYPE "%s"
#define TYPE char*
START_TEST(STRCAT)
{
    char dest[HALF] = "......\0";

    CHECK(strcat(dest, "oooooo"));

    {
        char s21[HALF] = "....\0";
        char std[HALF] = "....\0";

        s21_strcat(s21, "oooo");
        strcat(s21, "oooo"); 

        ck_assert_str_eq(s21, std);
    }

    {
        char s21[HALF] = "......\0";
        char std[HALF] = "......\0";

        s21_strcat(s21, "oooooo");
        strcat(s21, "oooooo");

        ck_assert_str_eq(s21, std);
    }

    {
        char s21[HALF - 1] = "......\0";
        char std[HALF - 1] = "......\0";

        s21_strcat(s21, "oooooo");
        strcat(s21, "oooooo");

        ck_assert_str_eq(s21, std);
    }
} END_TEST
#undef FTYPE
#undef TYPE
#endif

#if 0
#define FTYPE "%s"
#define TYPE char*
START_TEST(STRNCAT)
{
    char dest[HALF + 1] = "......\0";

    CHECK(strncat(dest, "oooooo", HALF));

    {
        char s21[HALF + 1] = "....\0";
        char std[HALF + 1] = "....\0";

        s21_strncat(s21, "oooo", HALF);
        strncat(s21, "oooo", HALF); 

        ck_assert_str_eq(s21, std);
    }

    {
        char s21[HALF + 1] = "......\0";
        char std[HALF + 1] = "......\0";

        s21_strncat(s21, "oooooo", HALF);
        strncat(s21, "oooooo", HALF);

        ck_assert_str_eq(s21, std);
    }

    {
        char s21[HALF] = "......\0";
        char std[HALF] = "......\0";

        s21_strncat(s21, "oooooo", HALF - 1);
        strncat(s21, "oooooo", HALF - 1);

        ck_assert_str_eq(s21, std);
    }
} END_TEST
#undef FTYPE
#undef TYPE
#endif

#if 0
#define FTYPE "%s"
#define TYPE char*
START_TEST(STRCHR)
{
    const char haystack[HALF] = "..o....o....\0";

    CHECK(strchr(haystack, 'o'));
    CHECK(strchr(haystack, 'x'));
    CHECK(strchr(haystack, '\0'));
} END_TEST
#undef FTYPE
#undef TYPE
#endif

#if 0
#define FTYPE "%d"
#define TYPE int
START_TEST(STRCMP)
{
    const char string[SIZE] = "............ooooooooooo\0";
    const char  other[SIZE] = "............ooooooooooo\0";

    CHECK(strcmp(string, string));
    CHECK(strcmp(string, &string[HALF - 1]));
} END_TEST
#endif

#if 0
#define FTYPE "%d"
#define TYPE int
START_TEST(STRNCMP)
{
    const char string[SIZE] = "............ooooooooooo\0";
    const char  other[SIZE] = "............ooooooooooo\0";

    CHECK(strncmp(string, string, HALF));
    CHECK(strncmp(string, &string[HALF - 1], HALF));
    CHECK(strncmp(string, string, SIZE));

    CHECK(strncmp(string, other, SIZE / 2));
    CHECK(strncmp(string, &other[HALF - 1], HALF));

    CHECK(strncmp(string, string, 0));
} END_TEST
#undef FTYPE
#undef TYPE
#endif

#if 1
#define FTYPE "%s"
#define TYPE char*
START_TEST(STRCPY) {
  {
    char src[SIZE] = "ooooooooooooooooooooooo\0";
    char dest[SIZE] = ".......................\0";

    s21_strcpy(dest, src);
    ck_assert_str_eq(dest, src);
  }

  {
    char src[SIZE] = "ooooooooooooooooooooooo\0";
    char dest[SIZE] = ".......................\0";

    CHECK(strcpy(dest, src));
  }
}
END_TEST
#undef FTYPE
#undef TYPE
#endif

#if 1
#define FTYPE "%s"
#define TYPE char*
START_TEST(STRNCPY) {
  {
    char src[SIZE] = "ooooooooooooooooooooooo\0";
    char dest[SIZE] = ".......................\0";

    s21_strncpy(dest, src, SIZE);
    ck_assert_str_eq(dest, src);
  }

  {
    char src[SIZE] = "ooooooooooooooooooooooo\0";
    char dest[SIZE] = ".......................\0";

    CHECK(strncpy(dest, src, SIZE));
  }

  {
    char s21[SIZE] = ".......................\0";
    char std[SIZE] = ".......................\0";

    char src[4] = {'o', 'o', 'o', 'o'};

    const size_t offset = (SIZE - sizeof(src));
    const size_t slice_size = sizeof(src);

    s21_strncpy(&s21[offset], src, slice_size);
    strncpy(&std[offset], src, slice_size);

    ck_assert_mem_eq(std, s21, SIZE);
  }

  {
    char s21[SIZE] = ".oooooooooooooooooooooo\0";
    char std[SIZE] = ".oooooooooooooooooooooo\0";

    // NOTE(pottluci): "..ooooooooooooooooooo???"
    ck_assert_mem_eq(strncpy(&std[1], &std[0], SIZE - 1) - 1,
                     s21_strncpy(s21 + 1, s21, SIZE - 1) - 1, SIZE);
  }

  {
    char s21[SIZE] = ".xxxxxxxxxxxxxxxxxxxxxx\0";
    char std[SIZE] = ".xxxxxxxxxxxxxxxxxxxxxx\0";

    // NOTE(pottluci): "xxxxxxxxxxxxxxxxxxxxxxxx"
    ck_assert_mem_eq(strncpy(&std[0], &std[1], SIZE - 1),
                     s21_strncpy(&s21[0], &s21[1], SIZE - 1), SIZE);
  }
}
END_TEST
#undef FTYPE
#undef TYPE
#endif

#if 0
#define FTYPE "%ld"
#define TYPE size_t
START_TEST(STRCSPN)
{
    char string[SIZE] = ".....a...o.............\0";

    CHECK(strcspn(string, "o"));
    CHECK(strcspn(string, "x"));

    CHECK(strcspn(string, "ao"));
} END_TEST
#undef FTYPE
#undef TYPE
#endif

#if 0
#define FTYPE "%ld"
#define TYPE size_t
START_TEST(STRLEN)
{
    char string[SIZE] = ".......................\0";

    CHECK(strlen(string));
} END_TEST
#endif

#if 0
#define FTYPE "%s"
#define TYPE char*
START_TEST(STRPBRK)
{
    char string[SIZE] = ".......o...a...........\0";

    CHECK(strpbrk(string, "ao"));
    CHECK(strpbrk(string, "oa"));

    CHECK(strpbrk(string, "xoa"));
    CHECK(strpbrk(string, "x"));
} END_TEST
#endif

#if 0
#define FTYPE "%s"
#define TYPE char*
START_TEST(STRRCHR)
{
    const char haystack[HALF] = "..o....o...\0";

    CHECK(strrchr(haystack, 'o'));
    CHECK(strrchr(haystack, 'x'));
    CHECK(strrchr(haystack, '\0'));
} END_TEST
#undef FTYPE
#undef TYPE
#endif

#if 0
#define FTYPE "%ld"
#define TYPE size_t
START_TEST(STRSPN)
{
    char string[SIZE] = ".....a...o.............\0";

    CHECK(strcspn(string, "."));
    CHECK(strcspn(string, "x"));

    CHECK(strcspn(string, ".a"));
} END_TEST
#undef FTYPE
#undef TYPE
#endif

#if 0
#define FTYPE "%s"
#define TYPE char*
START_TEST(STRSTR)
{
    char string[SIZE] = ".......oooo..oooo...ooo\0";

    CHECK(strcspn(string, "oooo"));
    CHECK(strcspn(string, "oooo\0"));

    CHECK(strcspn(string, "ooooo"));
    CHECK(strcspn(string, "ooo"));
    CHECK(strcspn(string, "xxx"));
} END_TEST
#endif

#if 0
#define FTYPE "%s"
#define TYPE char*
START_TEST(STRTOK)
{
    char string[SIZE] = "token.token.token\0";
    
    CHECK(strtok("token.token.token", "."));
    CHECK(strtok("token.token.token", "x"));

    char extd_string[SIZE] = ".token.token.token.\n";
    CHECK(strtok("token.token.token", "."));

} END_TEST
#undef FTYPE
#undef TYPE
#endif

#if 1
START_TEST(STRERROR) {
  for (int error = 0; error < 256; ++error) {
    ck_assert_str_eq(s21_strerror(error), strerror(error));
  }
  for (int error = 0; error > -256; --error) {
    ck_assert_str_eq(s21_strerror(error), strerror(error));
  }
}
END_TEST
#endif

#if 0
START_TEST(TO_UPPER) {
    const char uppercase_string[HALF] = "FOO";
    const char lowercase_string[HALF] = "foo";

    ck_assert_str_eq(s21_to_upper(lowercase_string), uppercase_string);

    const char unaffected[SIZE * 2] = "0123456789`~!@#$%^&*()-=+[]{};:'\"\\|<,.>?/\0";

    ck_assert_str_eq(s21_to_lower(unaffected), unaffected);

    ck_assert_ptr_null(s21_to_upper(NULL));
} END_TEST
#endif

#if 0
START_TEST(TO_LOWER) {
    const char uppercase_string[HALF] = "FOO";
    const char lowercase_string[HALF] = "foo";

    ck_assert_str_eq(s21_to_lower(uppercase_string), lowercase_string);

    const char unaffected[SIZE * 2] = "0123456789`~!@#$%^&*()-=+[]{};:'\"\\|<,.>?/\0";

    ck_assert_str_eq(s21_to_lower(unaffected), unaffected);

    ck_assert_ptr_null(s21_to_lower(NULL));
} END_TEST
#endif

#if 0
START_TEST(INSERT) {

    {
        const char original[HALF] = "............\0";
        const char modified[HALF] = "...oooo.........\0";

        ck_assert_str_eq(s21_insert("ooo", original, 3), modified);
    }

    {
        const char original[HALF] = "...........\0";
        const char modified[HALF] = "...........oooo\0";

        ck_assert_str_eq(s21_insert("ooo", original, 11), modified);
    }


    {
        const char original[HALF] = "...........\0";
        const char modified[HALF] = "...........oooo\0";

        ck_assert_str_eq(s21_insert("ooo", original, 12), modified);
    }

    ck_assert_ptr_null(s21_insert(NULL, original, 3));
    ck_assert_ptr_null(s21_insert("oooo", NULL, 3));
    ck_assert_ptr_null(s21_insert(NULL, original, 3));
} END_TEST
#endif

#if 0
START_TEST(TRIM) {
    {
        const char original[HALF] = "...[ BRUH ]XXX\0";
        const char modified[HALF] = "BRUH\0";

        const char charset[] = ".[X\0";

        ck_assert_str_eq(s21_trim(original, charset), modified);
    }

    {
        const char original[HALF] = "...........\0";
        const char modified[HALF] = "";

        const char charset[] = "x\0";

        ck_assert_str_eq(s21_trim(original, charset), modified);
    }

    ck_assert_ptr_null(s21_trim(NULL, charset));
    ck_assert_ptr_null(s21_trim(original, NULL));
} END_TEST
#endif

static const TTest** test[] = {
    &STRERROR, &STRCPY, &STRNCPY, &MEMCPY, &MEMSET, &MEMMOVE, &MEMCMP, &MEMCHR,
};

Suite* setup_suite(void) {
  Suite* suite = suite_create("s21_string");
  TCase* core = tcase_create("Core");

  for (int i = 0; i < TESTS_COUNT; ++i) {
    tcase_add_test(core, *test[i]);
  }

  suite_add_tcase(suite, core);

  return suite;
}

int main(void) {
  Suite* suite = setup_suite();
  SRunner* runner = srunner_create(suite);

  // NOTE(pottluci): "-" outputs to stdout.
  //                       v
  srunner_set_tap(runner, "-");

  srunner_run_all(runner, CK_MINIMAL);
  srunner_ntests_failed(runner);

  srunner_free(runner);

  return 0;
}
