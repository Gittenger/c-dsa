#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "string_utils.h"



#define ASSERT_TRUE(expr) do { \
    if (!(expr)) { \
        printf("❌ FAIL: %s at %s:%d\n", #expr, __FILE__, __LINE__); \
        return 1; \
    } \
} while(0)

#define ASSERT_STREQ(a,b) do { \
    if (strcmp((a), (b)) != 0) { \
        printf("❌ FAIL: \"%s\" != \"%s\" at %s:%d\n", (a), (b), __FILE__, __LINE__); \
        return 1; \
    } \
} while(0)

static int test_is_palindrome(void) {
    ASSERT_TRUE(is_palindrome("") == true);
    ASSERT_TRUE(is_palindrome("a") == true);
    ASSERT_TRUE(is_palindrome("aa") == true);
    ASSERT_TRUE(is_palindrome("ab") == false);
    ASSERT_TRUE(is_palindrome("abba") == true);
    ASSERT_TRUE(is_palindrome("abcd") == false);
    return 0;
}

static int test_reverse_str(void) {
    char b1[32] = "abcd";  reverse_str(b1); ASSERT_STREQ(b1, "dcba");
    char b2[32] = "";      reverse_str(b2); ASSERT_STREQ(b2, "");
    char b3[32] = "a";     reverse_str(b3); ASSERT_STREQ(b3, "a");
    char b4[32] = "abba";  reverse_str(b4); ASSERT_STREQ(b4, "abba");
    return 0;
}

int main(void) {
    if (test_is_palindrome()) return 1;
    if (test_reverse_str()) return 1;
    printf("✅ All tests passed.\n");

    return 0;
}