#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_SIZE 100

struct Stack {
    int top;
    int array[MAX_SIZE];
};

struct Stack* createStack() {
    struct Stack* stack = (struct Stack*) malloc(sizeof(struct Stack));
    stack->top = -1;
    return stack;
};

int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

int peek(struct Stack* stack) {
    return stack->array[stack->top];
}

int pop(struct Stack* stack) {
    if (!isEmpty(stack))
        return stack->array[stack->top--];
    return '$';
}

void push(struct Stack* stack, int op) {
    stack->array[++stack->top] = op;
}

int isOperand(char ch) {
    return isdigit(ch);
}

int precedence(char ch) {
    switch (ch) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
    }
    return -1;
}

int applyOp(int a, int b, char op){
    switch(op){
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b;
    }
}

int evaluate(char* tokens){
    int i;
    struct Stack* values = createStack();
    struct Stack* ops = createStack();
    
    for(i = 0; i < strlen(tokens); i++){
        if(tokens[i] == ' ')
            continue;
        else if(isdigit(tokens[i])){
            int val = 0;
            while(i < strlen(tokens) && isdigit(tokens[i])){
                val = (val*10) + (tokens[i]-'0');
                i++;
            }
            push(values, val);
            i--;
        }
        else{
            while(!isEmpty(ops) && precedence(peek(ops)) >= precedence(tokens[i])){
                int val2 = pop(values);
                int val1 = pop(values);
                char op = pop(ops);
                push(values, applyOp(val1, val2, op));
            }
            push(ops, tokens[i]);
        }
    }
    while(!isEmpty(ops)){
        int val2 = pop(values);
        int val1 = pop(values);
        char op = pop(ops);
        push(values, applyOp(val1, val2, op));
    }
    return pop(values);
}

int main() {
    char exp[100];
    printf("Enter an expression: ");
    fgets(exp, 100, stdin);
    exp[strcspn(exp, "\n")] = 0; 
    printf("Answer is %d\n", evaluate(exp));
    return 0;
}