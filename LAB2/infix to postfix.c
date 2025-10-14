#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

char stack[MAX];
int top = -1;


void push(char c) {
    if (top == MAX - 1) {
        printf("Stack overflow\n");
        return;
    }
    stack[++top] = c;
}

char pop() {
    if (top == -1) {
        printf("Stack underflow\n");
        return -1;
    }
    return stack[top--];
}

char peek() {
    if (top == -1)
        return -1;
    return stack[top];
}


int precedence(char op) {
    switch (op) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
        default:
            return -1;
    }
}


int associativity(char op) {
    if (op == '^') return 1;
    return 0;
}


void infixToPostfix(char* infix, char* postfix) {
    int i, j = 0;
    char ch;

    for (i = 0; infix[i] != '\0'; i++) {
        ch = infix[i];


        if (isalnum(ch)) {
            postfix[j++] = ch;
        }

        else if (ch == '(') {
            push(ch);
        }

        else if (ch == ')') {
            while (peek() != '(' && top != -1) {
                postfix[j++] = pop();
            }
            pop();
        }

        else {
            while (top != -1 && peek() != '(' &&
                ((precedence(ch) < precedence(peek())) ||
                (precedence(ch) == precedence(peek()) && associativity(ch) == 0))) {
                postfix[j++] = pop();
            }
            push(ch);
        }
    }


    while (top != -1) {
        postfix[j++] = pop();
    }

    postfix[j] = '\0';
}


int main() {
    char infix[MAX], postfix[MAX];

    printf("Enter infix expression: ");
    scanf("%s", infix);

    infixToPostfix(infix, postfix);

    printf("Postfix expression: %s\n", postfix);

    return 0;
}
