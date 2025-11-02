#include <string.h>
#include "string_utils.h"

void reverse_str(char *s) {
    size_t n = strlen(s);
    if (n == 0) return;
    size_t i = 0, j = n - 1;
    while (i < j) {
        char tmp = s[i];
        s[i] = s[j];
        s[j] = tmp;

        i++;
        j--;
    }
}