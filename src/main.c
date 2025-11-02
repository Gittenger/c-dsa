#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "string_utils.h"


#define ASSERT_TRUE(expr) do  { \
    if (!(expr)) { \
        printf("❌ FAIL: %s at %s:%d\n", #expr, __FILE__, __LINE__); \
        return 1; \
    } \
} while(0)


int main(int argc, char **argv) {
    // If you pass an arg, run the function on it and print result (quick manual test)
    if (argc > 1) {
        const char *cmd = argv[1];
        if (strcmp(cmd, "pal") == 0 && argc > 2) {
            printf("%s -> %s\n", argv[2], is_palindrome(argv[2]) ? "true" : "false");
        } else if (strcmp(cmd, "rev") == 0 && argc > 2) {
            char buf[1024];
            snprintf(buf, sizeof(buf), "%s", argv[2]);
            reverse_str(buf);
            printf("%s\n", buf);
            return 0;
        }
        return 0;
    }

    printf("Usage:\n  app pal <word>\n  app rev <word>\n");
    return 0;
}
