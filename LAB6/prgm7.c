#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
};

struct Node* head = NULL;

// Create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// a) Create doubly linked list (Insert at end)
void createList(int value) {
    struct Node* newNode = createNode(value);

    if (head == NULL) {
        head = newNode;
        return;
    }

    struct Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    newNode->prev = temp;
}

// b) Insert a new node to the left of a node with a specific value
void insertLeft(int target, int value) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct Node* temp = head;

    while (temp != NULL && temp->data != target)
        temp = temp->next;

    if (temp == NULL) {
        printf("Node with value %d not found\n", target);
        return;
    }

    struct Node* newNode = createNode(value);

    if (temp == head) {
        // inserting before the first node
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    } else {
        newNode->prev = temp->prev;
        newNode->next = temp;
        temp->prev->next = newNode;
        temp->prev = newNode;
    }
}

// c) Delete a node based on a specific value
void deleteNode(int value) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct Node* temp = head;

    while (temp != NULL && temp->data != value)
        temp = temp->next;

    if (temp == NULL) {
        printf("Node with value %d not found\n", value);
        return;
    }

    if (temp == head) {
        head = temp->next;
        if (head != NULL)
            head->prev = NULL;
    } else {
        temp->prev->next = temp->next;
    }

    if (temp->next != NULL)
        temp->next->prev = temp->prev;

    free(temp);
    printf("Node %d deleted\n", value);
}

// d) Display the contents of the list
void display() {
    struct Node* temp = head;

    if (temp == NULL) {
        printf("List is empty\n");
        return;
    }

    printf("Doubly Linked List: ");
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Main
int main() {
    int choice, value, target;

    while (1) {
        printf("\n--- DOUBLY LINKED LIST MENU ---\n");
        printf("1. Create node\n");
        printf("2. Insert to the left of a node\n");
        printf("3. Delete a node by value\n");
        printf("4. Display list\n");
        printf("5. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                createList(value);
                break;

            case 2:
                printf("Enter target value: ");
                scanf("%d", &target);
                printf("Enter new value: ");
                scanf("%d", &value);
                insertLeft(target, value);
                break;

            case 3:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                deleteNode(value);
                break;

            case 4:
                display();
                break;

            case 5:
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
