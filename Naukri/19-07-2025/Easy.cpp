// Problem
/*
You will be given ‘Q’ queries. You need to implement a circular queue according to those queries. Each query will belong to one of these two types:

1 ‘X’: Enqueue element ‘X’ into the end of the nth queue. Returns true if the element is enqueued, otherwise false.

2: Dequeue the element at the front of the nth queue. Returns -1 if the queue is empty, otherwise, returns the dequeued element.
*/

// Code

class CircularQueue {
public:
    vector<int> v;
    int front;
    int rear;
    int size;

    CircularQueue(int n) {
        v = vector<int>(n, -1);
        front = -1;
        rear = -1;
        size = n;
    }


    bool enqueue(int value) {
        if ((rear + 1) % size == front) {
            // Queue is full
            return false;
        }

        if (front == -1) {
            // First element being inserted
            front = rear = 0;
        } else {
            rear = (rear + 1) % size;
        }

        v[rear] = value;
        return true;
    }


    int dequeue() {
        if (front == -1) {
            // Queue is empty
            return -1;
        }

        int val = v[front];

        if (front == rear) {
            // Only one element was present
            front = rear = -1;
        } else {
            front = (front + 1) % size;
        }

        return val;
    }
};