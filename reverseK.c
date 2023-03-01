#include <stdio.h>
#include <stdlib.h>
struct queue{
    int front;
    int rear;
    int capacity;
    int* array;
};
struct queue* createqueue(int capacity);
void enqueue(struct queue* q, int x);
int isFull(struct queue* q);
int isEmpty(struct queue* q);
void reverse(struct queue* q, int k);
int main(void)
{
    struct queue* q;
    q = createqueue(5);
    enqueue(q, 1);
    enqueue(q, 4);
    enqueue(q, 6);
    enqueue(q, 9);
    enqueue(q, 3);
    printf("Queue before reversal:\n");
    for (int i=0; i<q->capacity; i++)
    {
        printf("%d ", q->array[i]);
    }
    printf("\n");
    printf("Queue after reversal:\n");
    reverse(q, 3);
    return 0;
}
void reverse(struct queue* q, int k)
{
    if (k>5)
    {
        printf("Invalid input.\n");
    }
    else {
        int arr[5];
        for (int i=0; i<k; i++)
        {
            arr[i]=q->array[q->front+i];
        }
        for (int i=0; i<k; i++)
        {
            q->array[q->front+i]=arr[k-1-i];
        }
        for (int i=0; i<q->capacity; i++)
            printf("%d ", q->array[i]);
    }
}
struct queue* createqueue(int capacity)
{
    struct queue* q = (struct queue*)malloc(sizeof(struct queue));
    q->front = q->rear = -1;
    q->capacity = capacity;
    q->array = (int*)malloc(sizeof(int)*capacity);
    return q;
}
void enqueue(struct queue* q, int x)
{
    if (isFull(q)==1)
        return;
    q->array[++q->rear]=x;
    if (q->front==-1)
    {
        q->front++;
    }
}
int isFull(struct queue* q)
{
    if (q->rear==q->capacity-1)
    {
        return 1;
    }
    else return 0;
}
int isEmpty (struct queue* q)
{
    if (q->front==-1)
        return 1;
    else return 0;
}
