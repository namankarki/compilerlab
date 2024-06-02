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

// Structure to represent a follow set
struct FollowSet {
    char nonTerminal;
    char follow[MAX_LENGTH];
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

// Function to find the follow set for a given grammar
void findFollowSet(struct Rule rules[], int ruleCount, struct FollowSet followSets[], int followSetCount, char nonTerminal) {
    int i, j;
    for (i = 0; i < ruleCount; i++) {
        char* ptr = strchr(rules[i].production, nonTerminal);
        if (ptr) {
            while (*(ptr + 1)) {
                char symbol = *(ptr + 1);
                if (isTerminal(symbol)) {
                    addToSet(followSets[followSetCount].follow, symbol);
                    break;
                } else if (isNonTerminal(symbol)) {
                    char firstSet[MAX_LENGTH] = "";
                    int foundEpsilon = 0;
                    for (j = 0; j < ruleCount; j++) {
                        if (rules[j].nonTerminal == symbol) {
                            if (rules[j].production[0] == '$' || isTerminal(rules[j].production[0])) {
                                addToSet(firstSet, rules[j].production[0]);
                            } else {
                                findFollowSet(rules, ruleCount, followSets, followSetCount, rules[j].production[0]);
                                strcat(firstSet, followSets[followSetCount].follow);
                            }
                            if (strchr(rules[j].production, '$')) {
                                foundEpsilon = 1;
                            } else {
                                foundEpsilon = 0;
                                break;
                            }
                        }
                    }
                    if (foundEpsilon) {
                        ptr++;
                    }
                    strcat(followSets[followSetCount].follow, firstSet);
                } else {
                    break;
                }
            }
            if (!*(ptr + 1)) {
                for (j = 0; j < followSetCount; j++) {
                    if (followSets[j].nonTerminal == rules[i].nonTerminal) {
                        strcat(followSets[j].follow, followSets[followSetCount].follow);
                        break;
                    }
                }
            }
        }
    }
}

int main() {
    struct Rule rules[MAX_RULES];
    struct FollowSet followSets[MAX_RULES];
    int ruleCount, followSetCount;
    char nonTerminal;

    printf("Enter the number of production rules: ");
    scanf("%d", &ruleCount);
    getchar(); // Clear newline character from buffer

    printf("Enter the production rules in the format 'NonTerminal -> Production'\n");
    int i;
    for (i = 0; i < ruleCount; i++) {
        scanf("%c -> %[^\n]s", &rules[i].nonTerminal, rules[i].production);
        getchar(); // Clear newline character from buffer
    }

    printf("Enter the non-terminal whose follow set you want to find: ");
    scanf("%c", &nonTerminal);

    followSetCount = 0;
    for (i = 0; i < ruleCount; i++) {
        if (rules[i].nonTerminal == nonTerminal) {
            strcpy(followSets[followSetCount].follow, "$");
            followSets[followSetCount].nonTerminal = nonTerminal;
            followSetCount++;
            break;
        }
    }

    findFollowSet(rules, ruleCount, followSets, followSetCount, nonTerminal);

    printf("Follow set of %c : {%s}\n", nonTerminal, followSets[0].follow);

    return 0;
}

