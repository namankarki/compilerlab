#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SYMBOLS 100

// Define a structure for each entry in the symbol table
typedef struct {
    char name[50];
    int address;
} SymbolEntry;

// Define the symbol table structure
typedef struct {
    SymbolEntry entries[MAX_SYMBOLS];
    int count;
} SymbolTable;

// Function to initialize the symbol table
void initializeSymbolTable(SymbolTable *table) {
    table->count = 0;
}

// Function to insert a symbol into the symbol table
void insertSymbol(SymbolTable *table, char *name, int address) {
    if (table->count < MAX_SYMBOLS) {
        SymbolEntry *entry = &table->entries[table->count++];
        strncpy(entry->name, name, sizeof(entry->name));
        entry->address = address;
        printf("Inserted symbol: %s at address: %d\n", name, address);
    } else {
        printf("Symbol table full. Cannot insert symbol: %s\n", name);
    }
}

// Function to search for a symbol in the symbol table
int searchSymbol(SymbolTable *table, char *name) {
    int i; // Declare 'i' outside the loop to conform with C89 standard
    for (i = 0; i < table->count; i++) {
        if (strcmp(table->entries[i].name, name) == 0) {
            return table->entries[i].address;
        }
    }
    return -1; // Symbol not found
}

int main() {
    SymbolTable symbolTable;
    initializeSymbolTable(&symbolTable);

    // Insert some symbols into the table
    insertSymbol(&symbolTable, "var1", 100);
    insertSymbol(&symbolTable, "var2", 200);
    insertSymbol(&symbolTable, "var3", 300);

    // Search for a symbol
    int address = searchSymbol(&symbolTable, "var2");
    if (address != -1) {
        printf("Address of var2: %d\n", address);
    } else {
        printf("Symbol not found\n");
    }

    return 0;
}

