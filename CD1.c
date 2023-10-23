#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
enum TokenType {
    KEYWORD, IDENTIFIER, CONSTANT, OPERATOR, SPECIAL_SYMBOL
};
int isKeyword(char *str) {
    char *keywords[] = {"int", "float", "if", "else", "while", "for", "return"};
    int numKeywords = sizeof(keywords) / sizeof(keywords[0]);
    for (int i = 0; i < numKeywords; i++) {
        if (strcmp(str, keywords[i]) == 0) {
            return 1;
        }
    }
    return 0;
}
void tokenize(char *program) {
    char *token = strtok(program, " \t\n\r;(){}[],*+-/=<>&|!");
    while (token != NULL) {
        if (isKeyword(token)) {
            printf("Token: %s\t Type: KEYWORD\n", token);
        } else if (isalpha(token[0])) {
            printf("Token: %s\t Type: IDENTIFIER\n", token);
        } else if (isdigit(token[0]) || (token[0] == '-' && isdigit(token[1]))) {
            printf("Token: %s\t Type: CONSTANT\n", token);
        } else if (strchr("+-*/=<>!&|", token[0]) != NULL) {
            printf("Token: %s\t Type: OPERATOR\n", token);
        } else {
            printf("Token: %s\t Type: SPECIAL_SYMBOL\n", token);
        }
        token = strtok(NULL, " \t\n\r;(){}[],*+-/=<>&|!");
    }
}

int main() {
    char program[1000];

    printf("Enter the C program:\n");
    fgets(program, sizeof(program), stdin);

    printf("Identified Tokens:\n");
    tokenize(program);

    return 0;
}
