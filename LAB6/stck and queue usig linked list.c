#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

// create node
struct Node* createNode(int data) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// push (stack)
void push(struct Node **top, int data) {
    struct Node *newNode = createNode(data);
    newNode->next = *top;
    *top = newNode;
}

// pop (stack)
int pop(struct Node **top) {
    if (*top == NULL) {
        printf("Stack Underflow!\n");
        return -1;
    }
    struct Node *temp = *top;
    int val = temp->data;
    *top = temp->next;
    free(temp);
    return val;
}

// enqueue (queue)
void enqueue(struct Node **front, struct Node **rear, int data) {
    struct Node *newNode = createNode(data);

    if (*rear == NULL) {
        *front = *rear = newNode;
        return;
    }
    (*rear)->next = newNode;
    *rear = newNode;
}

// dequeue (queue)
int dequeue(struct Node **front, struct Node **rear) {
    if (*front == NULL) {
        printf("Queue Underflow!\n");
        return -1;
    }
    struct Node *temp = *front;
    int val = temp->data;
    *front = (*front)->next;

    if (*front == NULL)
        *rear = NULL;

    free(temp);
    return val;
}

// display list
void display(struct Node *head) {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node *stackTop = NULL;
    struct Node *qFront = NULL, *qRear = NULL;
    int choice, value;

    // MENU printed once
    printf("\n--- MENU ---\n");
    printf("1. Push (Stack)\n");
    printf("2. Pop (Stack)\n");
    printf("3. Display Stack\n");
    printf("4. Enqueue (Queue)\n");
    printf("5. Dequeue (Queue)\n");
    printf("6. Display Queue\n");
    printf("7. Exit\n");

    while (1) {
        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter value: ");
            scanf("%d", &value);
            push(&stackTop, value);
            break;

        case 2:
            printf("Popped: %d\n", pop(&stackTop));
            break;

        case 3:
            printf("Stack: ");
            display(stackTop);
            break;

        case 4:
            printf("Enter value: ");
            scanf("%d", &value);
            enqueue(&qFront, &qRear, value);
            break;

        case 5:
            printf("Dequeued: %d\n", dequeue(&qFront, &qRear));
            break;

        case 6:
            printf("Queue: ");
            display(qFront);
            break;

        case 7:
            exit(0);

        default:
            printf("Invalid choice!\n");
        }
    }
}
