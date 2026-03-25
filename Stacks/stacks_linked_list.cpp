#include <stdio.h>
#include <stdlib.h>

// Node structure
typedef struct Node {
    int val;
    struct Node* next;
} Node;

// Stack structure
typedef struct {
    Node* head;
    int size;
} Stack;

// Create new node
Node* newNode(int x) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->val = x;
    node->next = NULL;
    return node;
}

// Initialize stack
void init(Stack* s) {
    s->head = NULL;
    s->size = 0;
}

void push(int x){
    Node *element = newNode(x);
    element->next = head;
    head = element;
    size++;
}

int pop(){
    if(head == NULL) return -1;

    int value = head->val;
    Node* temp = head;
    head = head->next;
    free(temp);   // or delete temp (C++) /// for freeing teh emeory which is being deleted 
    size--;
    return value;
}

int top(){
    if(head == NULL) return -1;
    return head->val;
}

int isEmpty(Stack* s) {
    return (s->head == NULL);
}