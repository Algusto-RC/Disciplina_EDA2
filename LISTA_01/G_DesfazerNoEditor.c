#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STR_SIZE 101
#define MAX_STACK_SIZE 1000

typedef struct {
    char data[MAX_STACK_SIZE][MAX_STR_SIZE];
    int top;
} Stack;

void initializeStack(Stack *stack) {
    stack->top = -1;
}

int isStackEmpty(Stack *stack) {
    return stack->top == -1;
}

void push(Stack *stack, char *str) {
    if (stack->top < MAX_STACK_SIZE - 1) {
        stack->top++;
        strncpy(stack->data[stack->top], str, MAX_STR_SIZE);
    }
}

char* pop(Stack *stack) {
    if (isStackEmpty(stack)) {
        return "NULL";
    } else {
        return stack->data[stack->top--];
    }
}

int main() {
    Stack stack;
    initializeStack(&stack);

    char command[MAX_STR_SIZE + 10];
    while (fgets(command, sizeof(command), stdin)) {
        if (strncmp(command, "inserir ", 8) == 0) {
            char *str = command + 8;  // aponta para o começo da string a ser inserida
            str[strcspn(str, "\n")] = 0;  // remove a nova linha
            push(&stack, str);
        } else if (strncmp(command, "desfazer", 7) == 0) {
            printf("%s\n", pop(&stack));
        }
    }

    return 0;
}
