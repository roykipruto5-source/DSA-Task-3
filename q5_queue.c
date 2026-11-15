/* Q5: Enqueue and dequeue in a (linear) queue */
#include <stdio.h>
#define MAX 5

int q[MAX], front = 0, rear = -1;

void enqueue(int x) {
    if (rear == MAX - 1) { printf("Queue overflow\n"); return; }
    q[++rear] = x;
    printf("Enqueued %d\n", x);
}

void dequeue() {
    if (front > rear) { printf("Queue underflow\n"); return; }
    printf("Dequeued %d\n", q[front++]);
}

void display() {
    if (front > rear) { printf("Queue is empty\n"); return; }
    printf("Queue: ");
    for (int i = front; i <= rear; i++) printf("%d ", q[i]);
    printf("\n");
}

int main() {
    enqueue(10); enqueue(20); enqueue(30);
    display();
    dequeue(); dequeue();
    display();
    dequeue(); dequeue();
    return 0;
}
