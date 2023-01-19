#include <check.h>
#include <errno.h>
#include <string.h>

#include "s21_string.h"

#define TESTS_COUNT 1

#define CHECK(func) ck_assert(s21_##func == func) 

enum test_specific_value {
    SIZE = 24,
    HALF = SIZE / 2,
};

#if 0
START_TEST(MEMCHR) {
    const char haystack[SIZE] = "........o...........x...";

    CHECK(memchr(haystack, 'o', SIZE / 2));

    CHECK(memchr(haystack, 'x', SIZE / 2));
    CHECK(memchr(haystack, 'x', SIZE));
} END_TEST
#endif

#if 0
START_TEST(MEMCMP)
{
    const char string[SIZE] = "............oooooooooooo";
    const char  other[SIZE] = "............oooooooooooo";

    CHECK(memcmp(string, string, HALF));
    CHECK(memcmp(string, &string[HALF - 1], HALF));
    CHECK(memcmp(string, string, SIZE));

    CHECK(memcmp(string, other, SIZE / 2));
    CHECK(memcmp(string, &other[HALF - 1], HALF));

    CHECK(memcmp(string, string, 0));
} END_TEST
#endif

#if 0
START_TEST(MEMCPY)
{
    {
        char  src[SIZE] = "oooooooooooooooooooooooo";
        char dest[SIZE] = "........................";

        s21_memcpy(dest, src, SIZE);
        ck_assert_mem_eq(dest, src, SIZE);
    }
     
    {
        char  src[SIZE] = "oooooooooooooooooooooooo";
        char dest[SIZE] = "........................";

        CHECK(memcpy(dest, src, SIZE));
    }

    {
        char  s21[SIZE] = ".ooooooooooooooooooooooo";
        char  std[SIZE] = ".ooooooooooooooooooooooo";

        s21_memcpy(s21 + 1, s21, SIZE - 1);
        memcpy(std + 1, std, SIZE - 1);

        // NOTE(pottluci): "..oooooooooooooooooooo???" 
        ck_assert_mem_eq(std, s21, SIZE);
    }

    {
        char  s21[SIZE] = ".xxxxxxxxxxxxxxxxxxxxxxx";
        char  std[SIZE] = ".xxxxxxxxxxxxxxxxxxxxxxx";

        s21_memcpy(s21, s21 + 1, SIZE - 1);
        memcpy(std, std + 1, SIZE - 1);

        // NOTE(pottluci): "xxxxxxxxxxxxxxxxxxxxxxxx" 
        ck_assert_mem_eq(std, s21, SIZE);
    }

} END_TEST
#endif

#if 0
START_TEST(MEMMOVE)
{
    {
        char  src[SIZE] = "oooooooooooooooooooooooo";
        char dest[SIZE] = "........................";

        s21_memmove(dest, src, SIZE);
        ck_assert_mem_eq(dest, src, SIZE);
    }
     
    {
        char  src[SIZE] = "oooooooooooooooooooooooo";
        char dest[SIZE] = "........................";

        CHECK(memmove(dest, src, SIZE));
    }

    {
        char  s21[SIZE] = ".ooooooooooooooooooooooo";
        char  std[SIZE] = ".ooooooooooooooooooooooo";

        s21_memmove(s21 + 1, s21, SIZE - 1);
        memmove(std + 1, std, SIZE - 1);

        // NOTE(pottluci): ".ooooooooooooooooooooooo" 
        ck_assert_mem_eq(std, s21, SIZE);
    }

    {
        char  s21[SIZE] = ".xxxxxxxxxxxxxxxxxxxxxxx";
        char  std[SIZE] = ".xxxxxxxxxxxxxxxxxxxxxxx";

        s21_memmove(s21, s21 + 1, SIZE - 1);
        memmove(std, std + 1, SIZE - 1);

        // NOTE(pottluci): ".xxxxxxxxxxxxxxxxxxxxxxx" 
        ck_assert_mem_eq(std, s21, SIZE);
    }
} END_TEST
#endif

#if 0
START_TEST(MEMSET)
{
    char s21[SIZE] = "........................";
    char std[SIZE] = "........................";


    s21_memset(s21, 'o', SIZE);
    memset(std, 'o', SIZE);

    ck_assert_mem_eq(s21, std, SIZE);

    char src[SIZE] = "........................";
    CHECK(memset(src, 'o', SIZE));
} END_TEST
#endif

#if 0
START_TEST(STRCAT)
{
    char dest[HALF] = "......";

    CHECK(strcat(dest, "oooooo"));

    {
        char s21[HALF] = "....";
        char std[HALF] = "....";

        s21_strcat(s21, "oooo");
        strcat(s21, "oooo"); 

        ck_assert_str_eq(s21, std);
    }

    {
        char s21[HALF] = "......";
        char std[HALF] = "......";

        s21_strcat(s21, "oooooo");
        strcat(s21, "oooooo");

        ck_assert_str_eq(s21, std);
    }

    {
        char s21[HALF - 1] = "......";
        char std[HALF - 1] = "......";

        s21_strcat(s21, "oooooo");
        strcat(s21, "oooooo");

        ck_assert_str_eq(s21, std);
    }
} END_TEST
#endif

#if 0
START_TEST(STRNCAT)
{
    char dest[HALF + 1] = "......";

    CHECK(strncat(dest, "oooooo", HALF));

    {
        char s21[HALF + 1] = "....";
        char std[HALF + 1] = "....";

        s21_strncat(s21, "oooo", HALF);
        strncat(s21, "oooo", HALF); 

        ck_assert_str_eq(s21, std);
    }

    {
        char s21[HALF + 1] = "......";
        char std[HALF + 1] = "......";

        s21_strncat(s21, "oooooo", HALF);
        strncat(s21, "oooooo", HALF);

        ck_assert_str_eq(s21, std);
    }

    {
        char s21[HALF] = "......";
        char std[HALF] = "......";

        s21_strncat(s21, "oooooo", HALF - 1);
        strncat(s21, "oooooo", HALF - 1);

        ck_assert_str_eq(s21, std);
    }
} END_TEST
#endif

#if 0
START_TEST(STRCHR)
{
    const char haystack[HALF] = "..o....o....";

    CHECK(strchr(haystack, 'o'));
    CHECK(strchr(haystack, 'x'));
    CHECK(strchr(haystack, '\0'));
} END_TEST
#endif

#if 0
START_TEST(STRCMP)
{
    const char string[SIZE] = "............oooooooooooo";
    const char  other[SIZE] = "............oooooooooooo";

    CHECK(strcmp(string, string));
    CHECK(strcmp(string, &string[HALF - 1]));
} END_TEST
#endif

#if 0
START_TEST(STRNCMP)
{
    const char string[SIZE] = "............oooooooooooo";
    const char  other[SIZE] = "............oooooooooooo";

    CHECK(strncmp(string, string, HALF));
    CHECK(strncmp(string, &string[HALF - 1], HALF));
    CHECK(strncmp(string, string, SIZE));

    CHECK(strncmp(string, other, SIZE / 2));
    CHECK(strncmp(string, &other[HALF - 1], HALF));

    CHECK(strncmp(string, string, 0));
} END_TEST
#endif

#if 0
START_TEST(STRCPY)
{
    {
        char  src[SIZE] = "oooooooooooooooooooooooo";
        char dest[SIZE] = "........................";

        s21_strcpy(dest, src);
        ck_assert_str_eq(dest, src);
    }
     
    {
        char  src[SIZE] = "oooooooooooooooooooooooo";
        char dest[SIZE] = "........................";

        CHECK(strcpy(dest, src));
    }
} END_TEST
#endif

#if 0
START_TEST(STRNCPY)
{
    {
        char  src[SIZE] = "oooooooooooooooooooooooo";
        char dest[SIZE] = "........................";

        s21_strncpy(dest, src, SIZE);
        ck_assert_str_eq(dest, src);
    }
     
    {
        char  src[SIZE] = "oooooooooooooooooooooooo";
        char dest[SIZE] = "........................";

        CHECK(strncpy(dest, src, SIZE));
    }

    {
        char  s21[SIZE] = "........................";
        char  std[SIZE] = "........................";

        char  src[4] = {'o','o','o','o'};

        const int offset = (SIZE - sizeof(src)); 

        s21_strncpy(&s21[offset], src, sizeof(src));
        strncpy(&std[offset], src, sizeof(src));

        ck_assert_mem_eq(std, s21, SIZE);
    }

    {
        char  s21[SIZE] = ".ooooooooooooooooooooooo";
        char  std[SIZE] = ".ooooooooooooooooooooooo";

        s21_strncpy(s21 + 1, s21, SIZE - 1);
        strncpy(std + 1, std, SIZE - 1);

        // NOTE(pottluci): "..ooooooooooooooooooo???" 
        ck_assert_mem_eq(std, s21, SIZE);
    }

    {
        char  s21[SIZE] = ".xxxxxxxxxxxxxxxxxxxxxxx";
        char  std[SIZE] = ".xxxxxxxxxxxxxxxxxxxxxxx";

        s21_strncpy(s21, s21 + 1, SIZE - 1);
        strncpy(std, std + 1, SIZE - 1);

        // NOTE(pottluci): "xxxxxxxxxxxxxxxxxxxxxxxx" 
        ck_assert_mem_eq(std, s21, SIZE);
    }

} END_TEST
#endif

#if 0
START_TEST(STRCSPN)
{
    char string[SIZE] = ".....a...o..............";

    CHECK(strcspn(string, "o"));
    CHECK(strcspn(string, "x"));

    CHECK(strcspn(string, "ao"));
} END_TEST
#endif

#if 0
START_TEST(STRLEN)
{
    char string[SIZE] = "........................";

    CHECK(strlen(string));
} END_TEST
#endif

#if 0
START_TEST(STRPBRK)
{
    char string[SIZE] = ".......o...a............";

    CHECK(strpbrk(string, "ao"));
    CHECK(strpbrk(string, "oa"));

    CHECK(strpbrk(string, "xoa"));
    CHECK(strpbrk(string, "x"));
} END_TEST
#endif

#if 0
START_TEST(STRRCHR)
{
    const char haystack[HALF] = "..o....o....";

    CHECK(strrchr(haystack, 'o'));
    CHECK(strrchr(haystack, 'x'));
    CHECK(strrchr(haystack, '\0'));
} END_TEST
#endif

#if 0
START_TEST(STRSPN)
{
    char string[SIZE] = ".....a...o..............";

    CHECK(strcspn(string, "."));
    CHECK(strcspn(string, "x"));

    CHECK(strcspn(string, ".a"));
} END_TEST
#endif

#if 0
START_TEST(STRSTR)
{
    char string[SIZE] = ".......oooo..oooo...oooo";

    CHECK(strcspn(string, "oooo"));
    CHECK(strcspn(string, "oooo\0"));

    CHECK(strcspn(string, "ooooo"));
    CHECK(strcspn(string, "ooo"));
    CHECK(strcspn(string, "xxx"));
} END_TEST
#endif

#if 0
START_TEST(STRTOK)
{
    char string[SIZE] = "token.token.token";
    
    CHECK(strtok("token.token.token", "."));
    CHECK(strtok("token.token.token", "x"));

    char extd_string[SIZE] = ".token.token.token.";
    CHECK(strtok("token.token.token", "."));

} END_TEST
#endif

#if 1
START_TEST(STRERROR) {
    for (int error = 0; error < 256; ++error)
    {
        ck_assert_str_eq(s21_strerror(error), strerror(error));
    }
    for (int error = 0; error > -256; --error)
    {
        ck_assert_str_eq(s21_strerror(error), strerror(error));
    }

} END_TEST
#endif

static const TTest **test[] = {
    &STRERROR,
};

Suite *setup_suite(void) {
    Suite *suite = suite_create("s21_string");
    TCase *core  = tcase_create("Core");

    for (int i = 0; i < TESTS_COUNT; ++i) {
        tcase_add_test(core, *test[i]);
    }

    suite_add_tcase(suite, core);

    return suite;
}

int main(void) {
    Suite *suite = setup_suite();
    SRunner *runner = srunner_create(suite); 

    // NOTE(pottluci): "-" outputs to stdout.
    //                       v
    srunner_set_tap(runner, "-"); 

    srunner_run_all(runner, CK_MINIMAL);
    srunner_ntests_failed(runner);

    srunner_free(runner);

    return 0;
}
