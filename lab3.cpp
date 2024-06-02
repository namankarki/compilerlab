#include <stdio.h>
#include <string.h>

// Function to check if a string matches the pattern (a+b)*
int matches_pattern(const char *string) {
    int i;
    for (i = 0; i < strlen(string); i++) {
        if (string[i] != 'a' && string[i] != 'b') {
            return 0; // If any character is not 'a' or 'b', the string does not match
        }
    }
    return 1; // The string matches if all characters are 'a' or 'b'
}

int main() {
    const char *language[] = {"", "a", "b", "ab", "ba", "aaa", "bbb", "abab", "baba", "aabbaabb"};
    int num_strings = sizeof(language) / sizeof(language[0]);
    int i;

    printf("Strings matching pattern (a+b)*:\n");

    for (i = 0; i < num_strings; i++) {
        if (matches_pattern(language[i])) {
            printf("%s matches the pattern (a+b)*\n", language[i]);
        } else {
            printf("%s does not match the pattern (a+b)*\n", language[i]);
        }
    }

    return 0;
}

