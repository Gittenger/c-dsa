#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "string_utils.h"

bool is_palindrome(const char *s) {
    size_t i = 0, j = strlen(s);
    if(j == 0) { return true; }
    j--;

    while (i < j) {
        #ifdef DEBUG
            printf("[DBG] compare s[%lu]=%c vs s[%lu]=%c\n", i, s[i], j, s[j]);
        #endif
        
        if(s[i] != s[j]) { return false; }
        i++; j--;
    }

    return true;
}