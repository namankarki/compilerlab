#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_RULES 10
#define MAX_LENGTH 10

// Structure to represent a production rule
struct Rule {
    char nonTerminal;
    char production[MAX_LENGTH];
};

// Function to check if a symbol is terminal
int isTerminal(char symbol) {
    return islower(symbol) || symbol == '$';
}

// Function to check if a symbol is non-terminal
int isNonTerminal(char symbol) {
    return isupper(symbol);
}

// Function to add a symbol to a set
void addToSet(char set[], char symbol) {
    if (!strchr(set, symbol)) {
        strncat(set, &symbol, 1);
    }
}

// Function to find the first set for a given grammar
void findFirstSet(struct Rule rules[], int ruleCount, char nonTerminal, char firstSet[]) {
    int i;
    for (i = 0; i < ruleCount; i++) {
        if (rules[i].nonTerminal == nonTerminal) {
            char symbol = rules[i].production[0];
            if (isTerminal(symbol) && symbol != '$') {
                addToSet(firstSet, symbol);
            } else if (isNonTerminal(symbol)) {
                findFirstSet(rules, ruleCount, symbol, firstSet);
            } else if (symbol == '$' && strlen(rules[i].production) == 1) {
                addToSet(firstSet, '$');
            } else {
                int j = 0;
                while (symbol != '\0') {
                    findFirstSet(rules, ruleCount, symbol, firstSet);
                    if (strchr(firstSet, '$')) {
                        j++;
                        symbol = rules[i].production[j];
                    } else {
                        break;
                    }
                }
            }
        }
    }
}

int main() {
    struct Rule rules[MAX_RULES];
    int ruleCount;
    char nonTerminal;
    char firstSet[MAX_LENGTH] = "";

    printf("Enter the number of production rules: ");
    scanf("%d", &ruleCount);
    getchar(); // Clear newline character from buffer

    printf("Enter the production rules in the format 'NonTerminal -> Production'\n");
    int i;
    for (i = 0; i < ruleCount; i++) {
        scanf("%c -> %[^\n]s", &rules[i].nonTerminal, rules[i].production);
        getchar(); // Clear newline character from buffer
    }

    printf("Enter the non-terminal whose first set you want to find: ");
    scanf("%c", &nonTerminal);

    findFirstSet(rules, ruleCount, nonTerminal, firstSet);

    printf("First set of %c : {%s}\n", nonTerminal, firstSet);

    return 0;
}


