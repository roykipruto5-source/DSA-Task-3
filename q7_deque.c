/* Q7: Double ended queue (circular array) */
#include <stdio.h>
#define SIZE 5

int dq[SIZE], front = -1, rear = -1;

int isFull()  { return (front == 0 && rear == SIZE - 1) || front == rear + 1; }
int isEmpty() { return front == -1; }

void insertFront(int x) {
    if (isFull()) { printf("Overflow\n"); return; }
    if (isEmpty()) front = rear = 0;
    else front = (front == 0) ? SIZE - 1 : front - 1;
    dq[front] = x;
}

void insertRear(int x) {
    if (isFull()) { printf("Overflow\n"); return; }
    if (isEmpty()) front = rear = 0;
    else rear = (rear == SIZE - 1) ? 0 : rear + 1;
    dq[rear] = x;
}

void deleteFront() {
    if (isEmpty()) { printf("Underflow\n"); return; }
    printf("Deleted from front: %d\n", dq[front]);
    if (front == rear) front = rear = -1;
    else front = (front == SIZE - 1) ? 0 : front + 1;
}

void deleteRear() {
    if (isEmpty()) { printf("Underflow\n"); return; }
    printf("Deleted from rear: %d\n", dq[rear]);
    if (front == rear) front = rear = -1;
    else rear = (rear == 0) ? SIZE - 1 : rear - 1;
}

void display() {
    if (isEmpty()) { printf("Deque is empty\n"); return; }
    for (int i = front; ; i = (i + 1) % SIZE) {
        printf("%d ", dq[i]);
        if (i == rear) break;
    }
    printf("\n");
}

int main() {
    insertRear(10); insertRear(20); insertFront(5); insertFront(1);
    display();
    deleteFront(); deleteRear();
    display();
    return 0;
}
