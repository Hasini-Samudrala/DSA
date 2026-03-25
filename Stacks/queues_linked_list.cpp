#include <stdio.h>
#include <stdlib.h>

// Node structure
typedef struct Node {
    int val;
    struct Node* next;
} Node;

// Queue structure
typedef struct {
    Node* front;   // head
    Node* rear;    // tail
    int size;
} Queue;

// Create new node
Node* newNode(int x) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->val = x;
    node->next = NULL;
    return node;
}

// Initialize queue
void init(Queue* q) {
    q->front = NULL;
    q->rear = NULL;
    q->size = 0;
}

// Enqueue (push)
void enqueue(Queue* q, int x) {
    Node* element = newNode(x);

    if (q->rear == NULL) {
        q->front = q->rear = element;
    } else {
        q->rear->next = element;
        q->rear = element;
    }
    q->size++;
}

// Dequeue (pop)
int dequeue(Queue* q) {
    if (q->front == NULL) {
        printf("Queue Underflow\n");
        return -1;
    }

    Node* temp = q->front;
    int value = temp->val;

    q->front = q->front->next;

    if (q->front == NULL) {
        q->rear = NULL;
    }

    free(temp);
    q->size--;

    return value;
}

// Peek (front element)
int peek(Queue* q) {
    if (q->front == NULL) {
        printf("Queue is empty\n");
        return -1;
    }
    return q->front->val;
}

// Check empty
int isEmpty(Queue* q) {
    return (q->front == NULL);
}