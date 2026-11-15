/* Q1: Circular queue using an array */
#include <stdio.h>
#define SIZE 5

int q[SIZE], front = -1, rear = -1;

int isFull()  { return (rear + 1) % SIZE == front; }
int isEmpty() { return front == -1; }

void enqueue(int x) {
    if (isFull()) { printf("Queue overflow\n"); return; }
    if (isEmpty()) front = 0;
    rear = (rear + 1) % SIZE;
    q[rear] = x;
}

int dequeue() {
    if (isEmpty()) { printf("Queue underflow\n"); return -1; }
    int x = q[front];
    if (front == rear) front = rear = -1;
    else front = (front + 1) % SIZE;
    return x;
}

void display() {
    if (isEmpty()) { printf("Queue is empty\n"); return; }
    for (int i = front; ; i = (i + 1) % SIZE) {
        printf("%d ", q[i]);
        if (i == rear) break;
    }
    printf("\n");
}

int main() {
    for (int i = 1; i <= 5; i++) enqueue(i * 10);
    display();
    printf("Dequeued: %d\n", dequeue());
    printf("Dequeued: %d\n", dequeue());
    enqueue(60); enqueue(70);   /* reuses freed space */
    display();
    return 0;
}
