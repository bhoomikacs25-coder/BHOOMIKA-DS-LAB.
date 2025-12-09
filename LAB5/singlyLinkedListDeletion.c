#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};
struct Node *head=NULL,*prev=NULL,*temp=NULL;

void createList(int n){
    int data;
    struct Node *newNode,*temp = NULL;
    if(n<=0){
        printf("Number of nodes should be greater than 0.\n");
        return;
    }
    for(int i=0;i<n;i++){
        newNode = (struct Node*) malloc(sizeof(struct Node));
        if(newNode==NULL){
            printf("Memory Allocation failed.\n");
            return;
        }
        printf("Enter data: ");
        scanf("%d",&data);
        newNode->data=data;
        newNode->next=NULL;
        if(head==NULL){
            head=newNode;
        }
        else{
            temp->next=newNode;
        }
        temp=newNode;
    }
        printf("Linked list created successfully.\n");
}

 void deleteFirst(){
    if(head==NULL){
        printf("List is empty.\n");
        return;
    }
    temp=head;
    head=temp->next;
    printf("Deleted first element %d.\n",temp->data);
    free(temp);
 }
void deleteLast(){
    if(head==NULL){
        printf("List is empty.\n");
        return;
    }
    if(head->next==NULL){
        printf("Deleted last element %d.\n",head->data);
        free(head);
        head=NULL;
        return;
    }
    temp = head;
    while(temp->next!=NULL){
        prev=temp;
        temp=temp->next;
    }
    printf("Deleted last element %d.\n",temp->data);
    prev->next=NULL;
    free(temp);
}
void deleteSpecific(value){
    if(head==NULL){
        printf("List is empty.\n");
        return;
    }
    if(head->data==value){
        printf("Deleted element %d.\n",value);
        free(head);
        head=NULL;
        return;
    }
    temp = head;
    while(temp!=NULL && temp->data!=value){
        prev=temp;
        temp=temp->next;
    }
    if(temp==NULL){
        printf("Element not found in list.\n");
        return;
    }
    printf("Deleted element %d.\n",value);
    prev->next=temp->next;
    free(temp);
}

void display(){
     struct Node *temp = head;
    if(head==NULL){
        printf("Linked list is empty.\n");
        return;
    }
    printf("Linked list: ");
    while(temp!=NULL){
        printf("%d -> ",temp->data);
        temp=temp->next;
    }
    printf("NULL\n");
}
int main(){
    int c,n,value;
    printf("\n Singly Linked List operations \n");
    printf("1. Create Linked list\n");
    printf("2. Delete at Beginning\n");
    printf("3. Delete at End\n");
    printf("4. Delete specific value\n");
    printf("5. Display List\n");
    printf("6. Exit\n");

    do{
        printf("\nEnter a choice: ");
        scanf("%d",&c);
        switch(c){
            case 1:{
                printf("Enter number of nodes: ");
                scanf("%d",&n);
                createList(n);
                break;
            }
            case 2:{
                deleteFirst();
                break;
            }
            case 3:{
                deleteLast();
                break;
            }
            case 4:{
                printf("Enter value: ");
                scanf("%d",&value);
                deleteSpecific(value);
                break;
            }
            case 5:{
                display();
                break;
            }
            case 6:{
                printf("Exiting...\n");
                break;
            }
            default :
                printf("Choose a valid choice.\n");
        }
    }while(c!=6);
}
