// Circular Queue implementation using Array
// Storage capacity of Circular queue will always be size of the array - 1

#include <stdio.h>
#include <stdlib.h>

struct Queue
{
    int size;
    int front;
    int rear;
    int *Q;
};

void create(struct Queue *q, int size);
void enqueue(struct Queue *q, int x);
int dequeue(struct Queue *q);
void display(struct Queue q);

int main()
{
    struct Queue q;
    create(&q, 5);

    enqueue(&q, 1);
    enqueue(&q, 2);
    enqueue(&q, 3);
    enqueue(&q, 4);
    enqueue(&q, 5);
    display(q);

    printf("Dequeued: %d\n", dequeue(&q));
    printf("Dequeued: %d\n", dequeue(&q));
    display(q);
    printf("Dequeued: %d\n", dequeue(&q));
    printf("Dequeued: %d\n", dequeue(&q));
}

void create(struct Queue *q, int size)
{
    q->size = size;
    q->front = q->rear = 0;
    q->Q = (int *)malloc(q->size * sizeof(int));
}

void enqueue(struct Queue *q, int x)
{
    int mod_q_index = (q->rear + 1) % q->size;
    if (mod_q_index == q->front)
        printf("Queue is full\n");
    else
    {
        q->rear = mod_q_index;
        q->Q[q->rear] = x;
    }
}

int dequeue(struct Queue *q)
{
    int x = -1;

    if (q->front == q->rear)
        printf("Queue is empty\n");
    else
    {
        q->front = (q->front + 1) % q->size;
        x = q->Q[q->front];
    }

    return x;
}

void display(struct Queue q)
{
    int i = q.front + 1;
    do
    {
        printf("%d ", q.Q[i]);
        i = (i + 1) % q.size;
    }
    while (i != (q.rear + 1) % q.size);
    printf("\n");
}