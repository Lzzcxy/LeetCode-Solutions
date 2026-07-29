#include <stdbool.h>
#include<stdlib.h>

#define MAX_CAPACITY 100


typedef struct {
    int stIn[MAX_CAPACITY];
    int inTop;
    int stOut[MAX_CAPACITY];
    int outTop;
} MyQueue;


MyQueue* myQueueCreate() {
    MyQueue *obj = (MyQueue*)malloc(sizeof(MyQueue));
    obj -> inTop = 0;
    obj -> outTop = 0;
    return obj;
}

void myQueuePush(MyQueue* obj, int x) {
    obj -> stIn[obj -> inTop]  = x;
    obj -> inTop = obj -> inTop + 1;
}

static void transfer(MyQueue *obj){
    if(obj -> outTop == 0){
        while(obj -> inTop > 0){
            obj -> inTop = obj -> inTop - 1;
            int val = obj -> stIn[obj -> inTop];
            obj -> stOut[obj -> outTop] = val;
            obj -> outTop = obj -> outTop + 1;
        }
    }
}

int myQueuePop(MyQueue* obj) {
    transfer(obj);
    obj -> outTop = obj -> outTop - 1;
    int val = obj -> stOut[obj -> outTop];
    return val;
}

int myQueuePeek(MyQueue* obj) {
    transfer(obj);
    int topIndex = obj -> outTop - 1;
    return obj -> stOut[topIndex];
}

bool myQueueEmpty(MyQueue* obj) {
    return obj -> inTop == 0 && obj -> outTop == 0;
}

void myQueueFree(MyQueue* obj) {
    free(obj);
}

/**
 * Your MyQueue struct will be instantiated and called as such:
 * MyQueue* obj = myQueueCreate();
 * myQueuePush(obj, x);
 
 * int param_2 = myQueuePop(obj);
 
 * int param_3 = myQueuePeek(obj);
 
 * bool param_4 = myQueueEmpty(obj);
 
 * myQueueFree(obj);
*/