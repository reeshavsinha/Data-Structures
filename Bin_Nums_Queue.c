#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000

struct Queue {
    int arr[MAX_SIZE];
    int front;
    int rear;
};

// Initialize queue
void initializeQueue(struct Queue* q) {
    q->front = -1;
    q->rear = -1;
}

// Check if the queue is full
int isFull(struct Queue* q) {
    return q->rear == MAX_SIZE - 1;
}

// Check if the queue is empty
int isEmpty(struct Queue* q) {
    return q->front == -1;
}

// Enqueue operation (insert at the rear)
void enqueue(struct Queue* q, int value) {
    if (isFull(q)) {
        printf("Queue is full!\n");
        return;
    }
    if (q->front == -1) {  // If queue is empty
        q->front = 0;
    }
    q->arr[++q->rear] = value;
}


// Display the queue
void display(struct Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        return;
    }
    printf("Queue elements: ");
    for (int i = q->front; i <= q->rear; i++) {
        printf("%d ", q->arr[i]);
    }
    printf("\n");
}

int BinGen(struct Queue* q, int n){
    int d, e, i=0;
    enqueue(q, 1);
    for(i = 0; i<n; i++){        
        for(int j = 0; j<=1; j++){
            if(i==0) {
                enqueue(q, (10+j));
                continue;
            }
            if((q->rear)+1 == n){
                return i;
            }
            d = ((q->arr[i]*10)+j);
            enqueue(q, d);
        }
    }

}

int main() {
    struct Queue q;
    initializeQueue(&q);
    int a = BinGen(&q, 24);
    display(&q);
    free(&q);
    
    return 0;
}






















