#include <stdio.h>
#include <time.h>
#define SIZE 10

int top = -1;
int stack[SIZE];

void push(int data){
    if(top >= SIZE - 1){
        printf("Stack is full.");
    } else {
        stack[++top] = data;
    }
}

int pop(){
    if(top < 0){
        printf("Stack is empty.");
        return -1;
    }
    return stack[top--];
}

int peep(int index){
    if(top - index + 1) {
        printf("Index out of bound");
        return -1;
    }
    return stack[top - index + 1];
}

void change(int index, int data){
    if(index < 0){
        printf("Enter valid index.");
    } else if (top - index + 1) {
        printf("Index is greater than number of elements.");
    } else {
        stack[top - index + 1] = data;
    }
}

void display(){
    for(int i = top; i >= 0; i--){
        printf("%d ", stack[i]);
    }
}

void main () {
    clock_t start, end, time_taken;
    start = clock();

    push(10);
    push(20);
    push(30);
    push(40);
    push(50);
    push(60);

    display();
    printf("\n");
    
    printf("%d ", pop());
    printf("%d ", pop());
    printf("\n");

    display();

    end = clock();

    time_taken = (double)(end - start) / CLOCKS_PER_SEC * 1000;
    printf("\nTime taken by algorithm : %d ", time_taken);
}