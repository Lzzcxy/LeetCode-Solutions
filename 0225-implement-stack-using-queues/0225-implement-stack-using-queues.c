#include <stdbool.h>
#include <stdlib.h>

#define MAX_CAPACITY 200

typedef struct {
    int data[MAX_CAPACITY];
    int front;
    int rear;
} Queue;

static Queue* createQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = 0;
    q->rear = 0;
    return q;
}

static bool isQueueEmpty(Queue* q) {
    return q->front == q->rear;
}

static void queuePush(Queue* q, int x) {
    q->data[q->rear] = x;
    q->rear = (q->rear + 1) % MAX_CAPACITY;
}

static int queuePop(Queue* q) {
    int val = q->data[q->front];
    q->front = (q->front + 1) % MAX_CAPACITY;
    return val;
}

static int queueFront(Queue* q) {
    return q->data[q->front];
}

static int queueSize(Queue* q) {
    return (q->rear - q->front + MAX_CAPACITY) % MAX_CAPACITY;
}

typedef struct {
    Queue* q;
} MyStack;

MyStack* myStackCreate() {
    MyStack* obj = (MyStack*)malloc(sizeof(MyStack));
    obj->q = createQueue();
    return obj;
}

void myStackPush(MyStack* obj, int x) {
    queuePush(obj->q, x);
    int sz = queueSize(obj->q) - 1;
    
    while (sz > 0) {
        int temp = queuePop(obj->q);
        queuePush(obj->q, temp);
        sz = sz - 1;
    }
}

int myStackPop(MyStack* obj) {
    return queuePop(obj->q);
}

int myStackTop(MyStack* obj) {
    return queueFront(obj->q);
}

bool myStackEmpty(MyStack* obj) {
    return isQueueEmpty(obj->q);
}

void myStackFree(MyStack* obj) {
    free(obj->q);
    free(obj);
}

/**
 * Your MyStack struct will be instantiated and called as such:
 * MyStack* obj = myStackCreate();
 * myStackPush(obj, x);
 
 * int param_2 = myStackPop(obj);
 
 * int param_3 = myStackTop(obj);
 
 * bool param_4 = myStackEmpty(obj);
 
 * myStackFree(obj);
*/