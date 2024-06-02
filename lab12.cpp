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


void generateAssemblyCode(struct Instruction* code, int codeSize) {
    printf("Assembly Code:\n");
    int i; 
    for (i = 0; i < codeSize; i++) {
        if (strcmp(code[i].opcode, "LOAD") == 0) {
            printf("MOV %s, %s\n", code[i].operand1, code[i].result);
        } else if (strcmp(code[i].opcode, "ADD") == 0) {
            printf("ADD %s, %s\n", code[i].operand1, code[i].operand2);
            printf("MOV %s, %s\n", code[i].result, code[i].operand1);
        }
      
    }
}

int main() {
    struct Instruction code[MAX_CODE_SIZE];
    int codeSize = 0;

    
    strcpy(code[codeSize].opcode, "LOAD");
    strcpy(code[codeSize].operand1, "8");
    strcpy(code[codeSize].operand2, "-");
    strcpy(code[codeSize].result, "T1");
    codeSize++;

    strcpy(code[codeSize].opcode, "ADD");
    strcpy(code[codeSize].operand1, "T1");
    strcpy(code[codeSize].operand2, "4");
    strcpy(code[codeSize].result, "T2");
    codeSize++;

    strcpy(code[codeSize].opcode, "LOAD");
    strcpy(code[codeSize].operand1, "5");
    strcpy(code[codeSize].operand2, "-");
    strcpy(code[codeSize].result, "T3");
    codeSize++;

    strcpy(code[codeSize].opcode, "ADD");
    strcpy(code[codeSize].operand1, "T2");
    strcpy(code[codeSize].operand2, "T3");
    strcpy(code[codeSize].result, "T4");
    codeSize++;

    // Generate assembly code
    generateAssemblyCode(code, codeSize);

    return 0;
}


