#include<stdio.h>
#include<stdlib.h>  // For malloc

struct queue
{
    int size;
    int front;
    int rear;
    int* arr;
};

void enqueue(struct queue *q, int data)
{
    if(q->rear == q->size - 1)
    {
        printf("The queue is full\n");
    }
    else
    {
        q->rear++;
        q->arr[q->rear] = data;
    }
}

void dequeue(struct queue *q)
{
    if(q->front == q->rear)
    {
        printf("The queue is empty and there is nothing left to delete\n");
    }
    else
    {
        q->front++;
        printf("Deleted element: %d\n", q->arr[q->front]);
    }
}

void printElements(struct queue *q)
{
    if(q->front == q->rear)
    {
        printf("The queue is empty\n");
    }
    else
    {
        printf("Current elements: ");
        for(int i = q->front + 1; i <= q->rear; i++)
        {
            printf("%d ", q->arr[i]);
        }
        printf("\n");
    }
}

int main()
{
    struct queue q;
    int length;
    printf("Enter the number of elements to be stored in the queue\n");
    scanf("%d", &length);
    q.size = length;
    q.front = -1;
    q.rear = -1;
    q.arr = (int*)malloc(q.size * sizeof(int));

    int choice, data;
    while(1)
    {
        printf("Menu operations for the queue data structure\n");
        printf("1. Insert new element into the queue\n");
        printf("2. Delete element from the queue\n");
        printf("3. Print elements\n");
        printf("4. Exit Program\n");
        printf("Choose your option from the above choices\n");
        printf("Enter the choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1: 
                printf("Enter the data which needs to be inserted: ");
                scanf("%d", &data);
                enqueue(&q, data);
                break;
            case 2: 
                dequeue(&q);
                break;
            case 3: 
                printElements(&q);
                break;
            case 4: 
                exit(0);
                break;
            default:
                printf("Please enter the correct choice from the above given options\n");
        }
    }

    free(q.arr);  // Freeing allocated memory
    return 0;
}
