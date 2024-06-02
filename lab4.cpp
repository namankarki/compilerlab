#include <stdio.h>

// DFA function to simulate the automaton
int dfa(int state, int input) {
    // Transition table
    int transition[8][2] = {
        {1, 2}, {3, 4}, {5, 6}, {7, 0}, {1, 2}, {3, 4}, {5, 6}, {7, 0}
    };

    return transition[state][input];
}

int main() {
    int roll_number;
    printf("Enter your class roll number: ");
    scanf("%d", &roll_number);

    // Convert roll number to binary and display it
    int binary[8];
    int i, state = 0;
    printf("Binary representation: ");
    for (i = 7; i >= 0; i--) {
        binary[i] = roll_number % 2;
        printf("%d", binary[i]);
        roll_number /= 2;
    }
    printf("\n");

    // Implement DFA
    for (i = 0; i < 8; i++) {
        state = dfa(state, binary[i]);
        printf("%d",state);
    }

    // Check if the final state is accepting (even)
    if (state == 0 || state == 4 || state == 6) {
        printf("The roll number is odd .\n");
    } else {
        printf("The roll number is even.\n");
    }

    return 0;
}


