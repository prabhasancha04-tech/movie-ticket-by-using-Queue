#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10  // maximum number of customers

char queue[MAX][50];  // array of strings to store customer names
int front = -1, rear = -1;

// Function to add a customer to the queue
void enqueue(char name[]) {
    if (rear == MAX - 1) {
        printf("Queue is full! No more customers can join.\n");
        return;
    }
    if (front == -1)  // first customer
        front = 0;
    rear++;
    strcpy(queue[rear], name);
    printf("%s joined the queue.\n", name);
}

// Function to serve (remove) a customer
void dequeue() {
    if (front == -1 || front > rear) {
        printf("No customers in queue.\n");
        return;
    }
    printf("%s got the ticket and left the queue.\n", queue[front]);
    front++;
}

// Function to display all customers in queue
void display() {
    if (front == -1 || front > rear) {
        printf("Queue is empty.\n");
        return;
    }
    printf("\nCurrent Queue:\n");
    for (int i = front; i <= rear; i++) {
        printf("%d. %s\n", i - front + 1, queue[i]);
    }
}

int main() {
    int choice;
    char name[50];

    while (1) {
        printf("\n--- Movie Ticket Booking System ---\n");
        printf("1. Join Queue\n");
        printf("2. Serve Customer\n");
        printf("3. Display Queue\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // clear input buffer

        switch (choice) {
            case 1:
                printf("Enter Customer Name: ");
                fgets(name, sizeof(name), stdin);
                name[strcspn(name, "\n")] = '\0'; // remove newline
                enqueue(name);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting system. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
}
