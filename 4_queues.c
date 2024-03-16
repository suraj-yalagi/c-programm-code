#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a customer
struct Customer {
    char name[50];
    float amountCredited;
};

// Structure to represent a queue
struct Queue {
    int front, rear, size;
    unsigned capacity;
    struct Customer* customers;
};

// Function to create a new customer
struct Customer newCustomer(const char* name, float amountCredited) {
    struct Customer customer;
    strcpy(customer.name, name);
    customer.amountCredited = amountCredited;
    return customer;
}

// Function to create a new queue
struct Queue* createQueue(unsigned capacity) {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->capacity = capacity;
    queue->front = queue->size = 0;
    queue->rear = capacity - 1;
    queue->customers = (struct Customer*)malloc(capacity * sizeof(struct Customer));
    return queue;
}

// Function to check if the queue is full
int isFull(struct Queue* queue) {
    return (queue->size == queue->capacity);
}

// Function to check if the queue is empty
int isEmpty(struct Queue* queue) {
    return (queue->size == 0);
}

// Function to enqueue a customer into the queue
void enqueue(struct Queue* queue, struct Customer customer) {
    if (isFull(queue))
        return;

    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->customers[queue->rear] = customer;
    queue->size++;
}

// Function to dequeue a customer from the queue
struct Customer dequeue(struct Queue* queue) {
    if (isEmpty(queue)) {
        struct Customer emptyCustomer;
        emptyCustomer.amountCredited = 0;
        return emptyCustomer;
    }

    struct Customer customer = queue->customers[queue->front];
    queue->front = (queue->front + 1) % queue->capacity;
    queue->size--;
    return customer;
}

// Function to find lucky winners and display results
void findLuckyWinners(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("No customers in the queue.\n");
        return;
    }

    struct Customer maxCustomer = queue->customers[0];
    struct Customer minCustomer = queue->customers[0];
    float totalAmount = 0;

    for (int i = 0; i < queue->size; i++) {
        struct Customer currentCustomer = queue->customers[i];

        if (currentCustomer.amountCredited > maxCustomer.amountCredited) {
            maxCustomer = currentCustomer;
        }

        if (currentCustomer.amountCredited < minCustomer.amountCredited) {
            minCustomer = currentCustomer;
        }

        totalAmount += currentCustomer.amountCredited;
    }

    float additionalAmountMax = 0.5 * minCustomer.amountCredited;
    float additionalAmountMin = 0.5 * maxCustomer.amountCredited;

    printf("Lucky Winner (Max Credited): %s\n", maxCustomer.name);
    printf("Additional Amount: %.2f\n", additionalAmountMax);

    printf("\nLucky Winner (Min Credited): %s\n", minCustomer.name);
    printf("Additional Amount: %.2f\n", additionalAmountMin);

    printf("\nTotal Credited Amount by all customers: %.2f\n", totalAmount);
}

int main() {
    struct Queue* queue = createQueue(10); // Assuming we have a capacity of 10 customers

    // Add customers with their credited amounts to the queue
    enqueue(queue, newCustomer("Customer 1", 5000));
    enqueue(queue, newCustomer("Customer 2", 8000));
    enqueue(queue, newCustomer("Customer 3", 2000));
    enqueue(queue, newCustomer("Customer 4", 3000));
    enqueue(queue, newCustomer("Customer 5", 7000));

    // Find and display the lucky winners
    findLuckyWinners(queue);

    // Free the allocated memory for the queue
    free(queue->customers);
    free(queue);

    return 0;
}
