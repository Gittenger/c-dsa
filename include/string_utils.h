#pragma once
#include <stdbool.h>
#include <stddef.h>

// Reverse a C-string in place (excludes terminating '\0')
bool is_palindrome(const char *s);

void reverse_str(char *s);

// (Optional) helpers you might add later
// size_t dynarray_push(...); etc.

