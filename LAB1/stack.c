#include <stdio.h>

#define N 5 // Maximum size of stack

int stack[N];
int top = -1;

// Function to push an element into the stack
void push() {
    int x;
    printf("Enter data: ");
    scanf("%d", &x);

    if (top == N - 1) {
        printf("Stack Overflow!\n");
    } else {
        top++;
        stack[top] = x;
        printf("%d pushed to stack.\n", x);
    }
}

// Function to pop an element from the stack
void pop() {
    int item;
    if (top == -1) {
        printf("Stack Underflow!\n");
    } else {
        item = stack[top];
        top--;
        printf("%d popped from stack.\n", item);
    }
}

// Function to see the top element of the stack
void peek() {
    if (top == -1) {
        printf("Stack is Empty!\n");
    } else {
        printf("Top element: %d\n", stack[top]);
    }
}

// Function to display all elements in the stack
void display() {
    if (top == -1) {
        printf("Stack is Empty!\n");
    } else {
        printf("Stack elements are:\n");
        for (int i = top; i >= 0; i--) {
            printf("%d\n", stack[i]);
        }
    }
}

int main() {
    int ch;

    do {
        printf("\n--- Stack Menu ---\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                peek();
                break;
            case 4:
                display();
                break;
            case 5:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (ch != 0);

    return 0;
}