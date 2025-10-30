#include <stdio.h>
#define MAX 5

int queue[MAX];
int front = -1, rear = -1;

void enqueue(int data) {
    if (rear == MAX - 1) {
        printf("\nQueue is Full! Cannot add more elements.\n");
    } else {
        if (front == -1)
            front = 0;
        rear++;
        queue[rear] = data;
        printf("%d added to the queue.\n", data);
    }
}

void dequeue() {
    if (front == -1 || front > rear) {
        printf("\nQueue is Empty! Cannot remove element.\n");
    } else {
        printf("%d removed from the queue.\n", queue[front]);
        front++;
    }
}

void display() {
    if (front == -1 || front > rear) {
        printf("\nQueue is Empty.\n");
    } else {
        printf("\nQueue Elements: ");
        for (int i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

int main() {
    int choice, value;
    printf("==== Queue Management System ====\n");

    while (1) {
        printf("\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &value);
                enqueue(value);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting program...\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
}
