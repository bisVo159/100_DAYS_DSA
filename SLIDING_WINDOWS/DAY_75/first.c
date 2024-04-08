#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_PRODUCTIONS 100
#define MAX_SYMBOLS 20

typedef struct {
    char lhs;
    char rhs[MAX_SYMBOLS];
} Production;

int numProductions;
Production productions[MAX_PRODUCTIONS];
bool isTerminal[MAX_SYMBOLS];

// Function prototypes
void computeFirst(char symbol);
void printFirstSet(char symbol);

int main() {
    printf("Enter the number of productions: ");
    scanf("%d", &numProductions);
    getchar(); // Consume newline character left in input buffer

    printf("Enter the productions (in the form 'A -> alpha'):\n");
    for (int i = 0; i < numProductions; ++i) {
        char buffer[100];
        fgets(buffer, sizeof(buffer), stdin);
        sscanf(buffer, "%c -> %s", &productions[i].lhs, productions[i].rhs);

        if (i == 0) {
            isTerminal[productions[i].lhs - 'A'] = false;
        }
    }

    for (int i = 0; i < numProductions; ++i) {
        for (int j = 0; j < strlen(productions[i].rhs); ++j) {
            if (productions[i].rhs[j] == '|') {
                isTerminal[productions[i].rhs[j + 1] - 'A'] = true;
            }
        }
    }

    for (int i = 0; i < numProductions; ++i) {
        computeFirst(productions[i].lhs);
    }

    printf("\nFirst Sets:\n");
    for (int i = 0; i < numProductions; ++i) {
        printFirstSet(productions[i].lhs);
    }

    return 0;
}

void computeFirst(char symbol) {
    for (int i = 0; i < numProductions; ++i) {
        if (productions[i].lhs == symbol) {
            char firstSymbol = productions[i].rhs[0];

            if (isTerminal[firstSymbol - 'A'] || firstSymbol == 'ε') {
                printf("First(%c) = {%c, }\n", symbol, firstSymbol);
            } else {
                computeFirst(firstSymbol);
            }
        }
    }
}

void printFirstSet(char symbol) {
    printf("First(%c) = {", symbol);

    for (int i = 0; i < numProductions; ++i) {
        if (productions[i].lhs == symbol) {
            char firstSymbol = productions[i].rhs[0];

            if (isTerminal[firstSymbol - 'A'] || firstSymbol == 'ε') {
                printf("%c, ", firstSymbol);
            } else {
                printFirstSet(firstSymbol);
            }
        }
    }

    printf("}\n");
}


