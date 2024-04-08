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
bool isVisited[MAX_SYMBOLS];

// Arrays to store First and Follow sets
char firstSet[MAX_SYMBOLS][MAX_SYMBOLS];
char followSet[MAX_SYMBOLS][MAX_SYMBOLS];

// Function prototypes
void computeFirst(char symbol);
void computeFollow(char symbol);

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

    // Compute First and Follow sets for each non-terminal symbol
    for (int i = 0; i < numProductions; ++i) {
        computeFirst(productions[i].lhs);
        for (int j = 0; j < MAX_SYMBOLS; ++j) {
            isVisited[j] = false;
        }
    }

    for (int i = 0; i < numProductions; ++i) {
        computeFollow(productions[i].lhs);
        for (int j = 0; j < MAX_SYMBOLS; ++j) {
            isVisited[j] = false;
        }
    }

    printf("\nFirst Sets:\n");
    for (int i = 0; i < numProductions; ++i) {
        printf("First(%c) = {", productions[i].lhs);
        for (int j = 0; j < MAX_SYMBOLS; ++j) {
            if (firstSet[productions[i].lhs - 'A'][j] != '\0') {
                printf("%c, ", firstSet[productions[i].lhs - 'A'][j]);
            }
        }
        printf("}\n");
    }

    printf("\nFollow Sets:\n");
    for (int i = 0; i < numProductions; ++i) {
        printf("Follow(%c) = {", productions[i].lhs);
        for (int j = 0; j < MAX_SYMBOLS; ++j) {
            if (followSet[productions[i].lhs - 'A'][j] != '\0') {
                printf("%c, ", followSet[productions[i].lhs - 'A'][j]);
            }
        }
        printf("}\n");
    }

    return 0;
}

void computeFirst(char symbol) {
    if (isVisited[symbol - 'A']) {
        return;
    }

    isVisited[symbol - 'A'] = true;

    for (int i = 0; i < numProductions; ++i) {
        if (productions[i].lhs == symbol) {
            char firstSymbol = productions[i].rhs[0];

            if (isTerminal[firstSymbol - 'A'] || firstSymbol == 'ε') {
                for (int j = 0; j < MAX_SYMBOLS; ++j) {
                    if (firstSet[symbol - 'A'][j] == '\0') {
                        firstSet[symbol - 'A'][j] = firstSymbol;
                        break;
                    }
                }
            } else {
                computeFirst(firstSymbol);
                for (int j = 0; j < MAX_SYMBOLS; ++j) {
                    if (firstSet[firstSymbol - 'A'][j] == '\0') {
                        break;
                    }
                    if (firstSet[firstSymbol - 'A'][j] != 'ε') {
                        for (int k = 0; k < MAX_SYMBOLS; ++k) {
                            if (firstSet[symbol - 'A'][k] == '\0') {
                                firstSet[symbol - 'A'][k] = firstSet[firstSymbol - 'A'][j];
                                break;
                            }
                        }
                    }
                }
            }
        }
    }
}

void computeFollow(char symbol) {
    if (isVisited[symbol - 'A']) {
        return;
    }

    isVisited[symbol - 'A'] = true;

    if (symbol == productions[0].lhs) {
        for (int i = 0; i < MAX_SYMBOLS; ++i) {
            if (followSet[symbol - 'A'][i] == '\0') {
                followSet[symbol - 'A'][i] = '$';
                break;
            }
        }
    }

    for (int i = 0; i < numProductions; ++i) {
        char *rhs = productions[i].rhs;
        int length = strlen(rhs);

        for (int j = 0; j < length; ++j) {
            if (rhs[j] == symbol) {
                if (j == length - 1) {
                    if (productions[i].lhs != symbol) {
                        computeFollow(productions[i].lhs);
                        for (int k = 0; k < MAX_SYMBOLS; ++k) {
                            if (followSet[productions[i].lhs - 'A'][k] == '\0') {
                                break;
                            }
                            if (followSet[productions[i].lhs - 'A'][k] != 'ε') {
                                for (int l = 0; l < MAX_SYMBOLS; ++l) {
                                    if (followSet[symbol - 'A'][l] == '\0') {
                                        followSet[symbol - 'A'][l] = followSet[productions[i].lhs - 'A'][k];
                                        break;
                                    }
                                }
                            }
                        }
                    }
                } else {
                    char nextSymbol = rhs[j + 1];
                    if (isTerminal[nextSymbol - 'A'] || nextSymbol == 'ε') {
                        for (int k = 0; k < MAX_SYMBOLS; ++k) {
                            if (followSet[symbol - 'A'][k] == '\0') {
                                followSet[symbol - 'A'][k] = nextSymbol;
                                break;
                            }
                        }
                    } else {
                        computeFirst(nextSymbol);
                        for (int k = 0; k < MAX_SYMBOLS; ++k) {
                            if (firstSet[nextSymbol - 'A'][k] == '\0') {
                                break;
                            }
                            if (firstSet[nextSymbol - 'A'][k] != 'ε') {
                                for (int l = 0; l < MAX_SYMBOLS; ++l) {
                                    if (followSet[symbol - 'A'][l] == '\0') {
                                        followSet[symbol - 'A'][l] = firstSet[nextSymbol - 'A'][k];
                                        break;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}


// S -> aB
// B -> Cd
// C -> bC | ε
// D -> cD | ε