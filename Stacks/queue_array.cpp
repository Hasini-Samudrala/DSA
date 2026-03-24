class ArrayQueue {
    int front, rear;
    int size;
    int* arr;

public:
    ArrayQueue(int n) {
        size = n;
        arr = new int[size];
        front = 0;
        rear = -1;
    }

    void push(int x) {
        if (rear == size - 1) {
            cout << "Queue Overflow\n";
            return;
        }
        rear++;
        arr[rear] = x;
    }

    int pop() {
        if (isEmpty()) {
            cout << "Queue Underflow\n";
            return -1;
        }
        return arr[front++];
    }

    int peek() {
        if (isEmpty()) {
            cout << "Queue is empty\n";
            return -1;
        }
        return arr[front];
    }

    bool isEmpty() {
        return front > rear;
    }
};