#include <stdio.h>
#include <time.h>
#define size 10

int front = -1, rear = -1;
int queue[size];

void offer(int data){
    if(front == -1){
        front = 0;
        queue[++rear] = data;
    } else if (rear >= size){
        printf("Queue is full.\n");
    } else {
        queue[++rear] = data;
    }
}

int poll(){
    if(front == -1){
        printf("Queue is already empty.\n");
        return -1;
    }
    return queue[front++];
}

void display(){
    for(int i = front; i <= rear; i++){
        printf("%d ", queue[i]);
    }
}

void main () {
    clock_t start, end, time_taken;
    start = clock();

    offer(10);
    offer(20);
    offer(30);
    offer(40);
    offer(50);
    offer(60);

    display();
    printf("\n");

    printf("%d ", poll());
    printf("%d ", poll());

    printf("\n");

    display();

    end = clock();

    time_taken = (double)(end - start) / CLOCKS_PER_SEC * 1000;
    printf("\nTime taken by algorithm : %d ", time_taken);
}