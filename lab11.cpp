#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CODE_SIZE 100

// Define the structure for intermediate code instructions
struct Instruction {
    char opcode[10];
    char operand1[10];
    char operand2[10];
    char result[10];
};

// Function to generate intermediate code for arithmetic expressions
void generateIntermediateCode(char* expression, struct Instruction* code, int* codeSize) {
    char* token = strtok(expression, "+-*/");

    while (token != NULL) {
        strcpy(code[*codeSize].opcode, "LOAD");
        strcpy(code[*codeSize].operand1, token);
        strcpy(code[*codeSize].operand2, "-");
        sprintf(code[*codeSize].result, "T%d", *codeSize + 1);
        (*codeSize)++;

        token = strtok(NULL, "+-*/");
        if (token != NULL) {
            strcpy(code[*codeSize].opcode, "ADD");
            strcpy(code[*codeSize].operand1, code[*codeSize - 1].result);
            strcpy(code[*codeSize].operand2, token);
            sprintf(code[*codeSize].result, "T%d", *codeSize + 1);
            (*codeSize)++;
        }
    }
}

// Function to print intermediate code
void printIntermediateCode(struct Instruction* code, int codeSize) {
    printf("Intermediate Code:\n");
    int i; // Variable 'i' declaration moved inside the function
    for (i = 0; i < codeSize; i++) { // Adjusted loop structure
        printf("%s %s %s %s\n", code[i].opcode, code[i].operand1, code[i].operand2, code[i].result);
    }
}

int main() {
    char expression[100];
    struct Instruction code[MAX_CODE_SIZE];
    int codeSize = 0;

    printf("Enter arithmetic expression: ");
    scanf("%s", expression);

    generateIntermediateCode(expression, code, &codeSize);
    printIntermediateCode(code, codeSize);

    return 0;
}

