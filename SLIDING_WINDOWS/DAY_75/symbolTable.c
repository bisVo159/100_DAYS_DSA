#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Enumeration for variable type
typedef enum {
    INT,
    FLOAT,
    CHAR
} Type;

// Structure to hold information about a symbol
typedef struct {
    char name[20];
    Type type;
    int value;
    int scope;
} Symbol;

// Structure to hold the symbol table
typedef struct {
    Symbol *symbols;
    int capacity;
    int size;
} SymbolTable;

// Initialize the symbol table
void initSymbolTable(SymbolTable *table, int capacity) {
    table->capacity = capacity;
    table->size = 0;
    table->symbols = (Symbol *)malloc(capacity * sizeof(Symbol));
}

// Add a symbol to the table
void addSymbol(SymbolTable *table, const char *name, Type type, int value, int scope) {
    if (table->size >= table->capacity) {
        printf("Symbol table is full.\n");
        return;
    }

    Symbol newSymbol;
    strncpy(newSymbol.name, name, 20);
    newSymbol.type = type;
    newSymbol.value = value;
    newSymbol.scope = scope;

    table->symbols[table->size++] = newSymbol;
}

// Find a symbol in the table and return its index
int findSymbol(SymbolTable *table, const char *name, int scope) {
    for (int i = table->size - 1; i >= 0; --i) {
        if (strcmp(table->symbols[i].name, name) == 0 && table->symbols[i].scope == scope) {
            return i;
        }
    }
    return -1;  // Symbol not found
}

// Print all symbols in the table
void printSymbolTable(SymbolTable *table) {
    printf("Symbol Table:\n");
    printf("Name\tType\tValue\tScope\n");
    for (int i = 0; i < table->size; ++i) {
        printf("%s\t", table->symbols[i].name);
        switch (table->symbols[i].type) {
            case INT:
                printf("INT\t");
                break;
            case FLOAT:
                printf("FLOAT\t");
                break;
            case CHAR:
                printf("CHAR\t");
                break;
        }
        printf("%d\t%d\n", table->symbols[i].value, table->symbols[i].scope);
    }
}

int main() {
    SymbolTable symbolTable;
    initSymbolTable(&symbolTable, 10);  // Initialize with capacity 10

    // Adding some sample symbols
    addSymbol(&symbolTable, "x", INT, 10, 0); // INT type, value 10, scope 0
    addSymbol(&symbolTable, "y", FLOAT, 20, 1); // FLOAT type, value 20, scope 1
    addSymbol(&symbolTable, "z", CHAR, 30, 0); // CHAR type, value 30, scope 0

    // Print the symbol table
    printSymbolTable(&symbolTable);

    // Find a symbol
    const char *searchName = "y";
    int foundIndex = findSymbol(&symbolTable, searchName, 1);
    if (foundIndex != -1) {
        printf("Found %s at index %d with value %d\n", searchName, foundIndex, symbolTable.symbols[foundIndex].value);
    } else {
        printf("Symbol %s not found.\n", searchName);
    }

    // Adding a new symbol
    addSymbol(&symbolTable, "w", INT, 40, 1); // INT type, value 40, scope 1
    printSymbolTable(&symbolTable);

    // Trying to add a symbol when the table is full
    addSymbol(&symbolTable, "overflow", FLOAT, 50, 2); // Attempting to add in scope 2

    free(symbolTable.symbols);  // Free allocated memory
    return 0;
}
