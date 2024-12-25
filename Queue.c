#include <stdio.h>
#include <stdlib.h>

#define QUEUE_SIZE 5

typedef struct {
    int items[QUEUE_SIZE];
    int front;
    int rear;
} CircularQueue;

void initializeQueue(CircularQueue* q) {
    q->front = 0;
    q->rear = 0;
}

// 다음 위치가 front와 같으면 큐가 가득 찼다고 판단
int isFull(CircularQueue* q) {
    return ((q->rear + 1) % QUEUE_SIZE) == q->front;
}

int isEmpty(CircularQueue* q) {
    return q->rear == q->front;
}

void enqueue(CircularQueue* q, int item) {
    if (isFull(q)) {
        printf("Queue is full\n");
        return;
    }
    q->rear = (q->rear +1) % QUEUE_SIZE;
    q->items[q->rear] = item;
}

int dequeue(CircularQueue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return -1;
    }
    q->front = (q->front + 1) % QUEUE_SIZE;
    return q->items[q->front];
}

void printQueue(CircularQueue* q) {
    printf("Queue contents: ");
    if (isEmpty(q)) {
        printf("The queue is Empty.\n");
        return;
    }
    int i = q->front;
    while (i != q->rear) {
        i = (i + 1) % QUEUE_SIZE;
        printf("%d", q->items[i]);
    }
    printf("\n");
}

int main() {
    CircularQueue q;
    initializeQueue(&q);

    enqueue(&q, 1);
    enqueue(&q, 2);
    enqueue(&q, 3);
    printf("Dequeue: %d\n", dequeue(&q));
    printf("Dequeue: %d\n", dequeue(&q));

    printQueue(&q);

    enqueue(&q, 4);
    enqueue(&q, 5);

    while (!isEmpty(&q)) {
        printf("Dequeue: %d\n", dequeue(&q));
    }
    printQueue(&q);

    return 0;
}