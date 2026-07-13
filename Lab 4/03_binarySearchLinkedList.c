#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct node {
    int info;
    struct node *next;
};

struct node* createNode(int num) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->info = num;
    newNode->next = NULL;
    return newNode;
}

void insertAtLast(struct node **head, int num) {
    struct node* newNode = createNode(num);

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    struct node* temp = *head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
}

struct node* findMid(struct node* start, struct node* end) {
    struct node *slow = start, *fast = start;

    while (fast != end && fast->next != end) {
        fast = fast->next;
        if (fast != end) {
            fast = fast->next;
            slow = slow->next;
        }
    }

    return slow;
}

int binarySearch(struct node* start, struct node* end, int target, int startIndex) {
    if (start == end)
        return -1;

    struct node* mid = findMid(start, end);

    int midIndex = startIndex;
    struct node* temp = start;
    while (temp != mid) {
        midIndex++;
        temp = temp->next;
    }

    if (mid->info == target)
        return midIndex;

    if (target < mid->info)
        return binarySearch(start, mid, target, startIndex);

    return binarySearch(mid->next, end, target, midIndex + 1);
}

void main() {
    clock_t start, end, time_taken;
    start = clock();

    struct node* head = NULL;

    insertAtLast(&head, 10);
    insertAtLast(&head, 20);
    insertAtLast(&head, 30);
    insertAtLast(&head, 40);
    insertAtLast(&head, 50);
    insertAtLast(&head, 60);

    int index = binarySearch(head, NULL, 20, 0);

    if (index != -1)
        printf("Element found at index %d\n", index);
    else
        printf("Element not found\n");

    end = clock();

    time_taken = (double)(end - start) / CLOCKS_PER_SEC * 1000;
    printf("\nTime taken by algorithm : %d ", time_taken);
}