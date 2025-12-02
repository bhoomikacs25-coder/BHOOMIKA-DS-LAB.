#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    struct Node* temp = *head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
}

void display(struct Node* head) {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void sortList(struct Node* head) {
    struct Node *i, *j;
    int temp;

    for (i = head; i != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            if (i->data > j->data) {
                temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }
}

void reverse(struct Node** head) {
    struct Node *prev = NULL, *curr = *head, *next = NULL;

    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    *head = prev;
}

struct Node* concatenate(struct Node* head1, struct Node* head2) {
    if (head1 == NULL) return head2;
    if (head2 == NULL) return head1;

    struct Node* temp = head1;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = head2;
    return head1;
}

int main() {
    struct Node *list1 = NULL, *list2 = NULL, *result = NULL;
    int choice, value;

    printf("\n--- MENU ---\n");
    printf("1. Insert into List 1\n");
    printf("2. Insert into List 2\n");
    printf("3. Display List 1\n");
    printf("4. Display List 2\n");
    printf("5. Sort List 1\n");      // Only List 1
    printf("6. Reverse List 1\n");   // Only List 1
    printf("7. Concatenate List 1 + List 2\n");
    printf("8. Exit\n");

    while (1) {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                insertEnd(&list1, value);
                break;

            case 2:
                printf("Enter value: ");
                scanf("%d", &value);
                insertEnd(&list2, value);
                break;

            case 3:
                printf("List 1: ");
                display(list1);
                break;

            case 4:
                printf("List 2: ");
                display(list2);
                break;

            case 5:
                sortList(list1);
                printf("List 1 sorted.\n");
                break;

            case 6:
                reverse(&list1);
                printf("List 1 reversed.\n");
                break;

            case 7:
                result = concatenate(list1, list2);
                printf("Concatenated List: ");
                display(result);
                break;

            case 8:
                exit(0);

            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}
