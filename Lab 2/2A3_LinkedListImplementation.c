#include <stdio.h>
#include <time.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

struct Node* createNode(int data){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertAtFirst(struct Node** head, int info){
    struct Node* newNode = createNode(info);
    if(*head == NULL){
        *head = newNode;
    } else {
        newNode->next = *head;
        *head = newNode;
    }
}

int deleteAtFirst(struct Node** head){
    if(*head == NULL){
        printf("List is already empty.");
        return -1;
    }
    struct Node* temp = *head;
    int info = temp->data;
    *head = temp->next;
    free(temp);
    return info;
}

void display(struct Node** head){
    struct Node* temp = *head;
    while(temp != NULL){
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
}

int main () {
    clock_t start, end;
    double time_taken;
    start = clock();

    struct Node* head = NULL;
    insertAtFirst(&head, 10);
    insertAtFirst(&head, 20);
    insertAtFirst(&head, 30);
    insertAtFirst(&head, 40);
    insertAtFirst(&head, 50);
    insertAtFirst(&head, 60);

    display(&head);
    printf("\n");

    printf("%d ", deleteAtFirst(&head));
    printf("%d ", deleteAtFirst(&head));

    printf("\n");

    display(&head);

    end = clock();

    time_taken = (double)(end - start) / CLOCKS_PER_SEC * 1000;
    printf("\nTime taken by algorithm : %f ", time_taken);
    return 0;
}