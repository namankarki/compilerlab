#include <stdio.h>
#include <ctype.h>

int isValidIdentifier(const char *str) {
    // If the first character is not a letter or underscore, it's not a valid identifier
    if (!isalpha(str[0]) && str[0] != '_') {
        return 0;
    }

    // Check the rest of the characters
    for (int i = 1; str[i] != '\0'; i++) {
        if (!isalnum(str[i]) && str[i] != '_') {
            return 0;
        }
    }

    // If all checks are passed, it is a valid identifier
    return 1;
}

int main() {
    char identifier[100];

    printf("Enter an identifier: ");
    scanf("%99s", identifier);

    if (isValidIdentifier(identifier)) {
        printf("\"%s\" is a valid identifier.\n", identifier);
    } else {
        printf("\"%s\" is not a valid identifier.\n", identifier);
    }

return 0;
}


