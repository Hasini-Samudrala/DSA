#include <stdio.h>
#include <stdbool.h>

#define MAX 100

typedef struct {
    int arr[MAX];
    int top;
} ArrayStack;

// Initialize
void init(ArrayStack *s) {
    s->top = -1;
}

// Check empty
bool isEmpty(ArrayStack *s) {
    return (s->top == -1);
}

// Push
void push(ArrayStack *s, int x) {
    if (s->top == MAX - 1) {
        printf("Stack Overflow\n");
        return;
    }
    s->arr[++(s->top)] = x;
}

// Pop
int pop(ArrayStack *s) {
    if (isEmpty(s)) {
        printf("Stack Underflow\n");
        return -1;
    }
    return s->arr[(s->top)--];
}

// Peek
int peek(ArrayStack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty\n");
        return -1;
    }
    return s->arr[s->top];
}