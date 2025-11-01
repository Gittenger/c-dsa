#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>

bool is_palindrome(const char *s){
    size_t i = 0, j = strlen(s);
    if (j == 0) { return true; }
    j--; // last index

    while (i < j){
        #ifdef DEBUG
            printf("[DBG] compare s[%lu]=%c vs s[%lu]=%c\n", i, s[i], j, s[j]);
        #endif
        
        if (s[i] != s[j]) { return false; }
        i++; j--;
    }

    return true;
}

#define ASSERT_TRUE(expr) do  { \
    if (!(expr)) { \
        printf("❌ FAIL: %s at %s:%d\n", #expr, __FILE__, __LINE__); \
        return 1; \
    } \
} while(0)


int main(int argc, char **argv) {
    // If you pass an arg, run the function on it and print result (quick manual test)
    if (argc > 1) {
        printf("%s -> %s\n", argv[1], is_palindrome(argv[1]) ? "true" : "false");
        return 0;
    }

    // Otherwise, run small built-in tests (instant feedback)
    ASSERT_TRUE(is_palindrome("") == true);
    ASSERT_TRUE(is_palindrome("a") == true);
    ASSERT_TRUE(is_palindrome("aa") == true);
    ASSERT_TRUE(is_palindrome("ab") == false);
    ASSERT_TRUE(is_palindrome("abba") == true);
    ASSERT_TRUE(is_palindrome("abcd") == false);

    printf("✅ All tests passed.\n");
    return 0;
}
