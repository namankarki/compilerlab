#include <stdio.h>
#include <ctype.h>
#include <string.h>

// Token types
enum TokenType {
    KEYWORD,
    IDENTIFIER,
    NUMBER,
    OPERATOR,
    SEPARATOR,
    INVALID
};

// Function to check if a string is a keyword
int isKeyword(char* word) {
    char keywords[6][10] = {"int", "float", "if", "else", "while", "for"};
    int i;
    for (i = 0; i < 6; i++) {
        if (strcmp(keywords[i], word) == 0) {
            return 1;
        }
    }
    return 0;
}

// Function to check if a character is an operator
int isOperator(char c) {
    char operators[] = "+-*/=!<>";
    int i;
    for (i = 0; operators[i]; i++) {
        if (operators[i] == c) {
            return 1;
        }
    }
    return 0;
}

// Function to check if a character is a separator
int isSeparator(char c) {
    char separators[] = ";,(){}";
    int i;
    for (i = 0; separators[i]; i++) {
        if (separators[i] == c) {
            return 1;
        }
    }
    return 0;
}

// Function to tokenize the input string
void tokenize(char* input) {
    char buffer[50];
    int bufferIndex = 0;
    int i;

    for (i = 0; input[i]; i++) {
        if (isalpha(input[i])) { // Identifier or keyword
            buffer[bufferIndex++] = input[i];
            while (isalnum(input[i + 1])) {
                buffer[bufferIndex++] = input[++i];
            }
            buffer[bufferIndex] = '\0';
            if (isKeyword(buffer)) {
                printf("(%d, %s)\n", KEYWORD, buffer);
            } else {
                printf("(%d, %s)\n", IDENTIFIER, buffer);
            }
            bufferIndex = 0;
        } else if (isdigit(input[i])) { // Number
            buffer[bufferIndex++] = input[i];
            while (isdigit(input[i + 1]) || input[i + 1] == '.') {
                buffer[bufferIndex++] = input[++i];
            }
            buffer[bufferIndex] = '\0';
            printf("(%d, %s)\n", NUMBER, buffer);
            bufferIndex = 0;
        } else if (isOperator(input[i])) { // Operator
            buffer[bufferIndex++] = input[i];
            printf("(%d, %s)\n", OPERATOR, buffer);
            bufferIndex = 0;
        } else if (isSeparator(input[i])) { // Separator
            buffer[bufferIndex++] = input[i];
            printf("(%d, %s)\n", SEPARATOR, buffer);
            bufferIndex = 0;
        } else if (!isspace(input[i])) { // Invalid character
            printf("(%d, %c)\n", INVALID, input[i]);
        }
    }
}

// Main function
int main() {
    char input[100];
    printf("Enter some code: ");
    fgets(input, sizeof(input), stdin);
    tokenize(input);
    return 0;
}

