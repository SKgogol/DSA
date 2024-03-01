#include<stdio.h>
#include<stdlib.h>
#define max 10
int queue_arr[max];
int front,rear;

void enqueue(int data)
{
  if(rear==max-1)
  printf("queue is full");

  else{
    rear++;
    queue_arr[rear]=data;
    }
}


void  dequeue()
{
    int del_value;
    if(rear==0)
    printf("Queue is empty");

    else{
        del_value=queue_arr[front];
        printf("the deleted value is %d\n",del_value);
        front++;
        }


}

int main()
{
    front=0;
    rear=-1;

    enqueue(4);
    enqueue(3);
    enqueue(6);
    enqueue(7);

    dequeue();



    for(int i=front;i<=rear;i++)
    {
        printf("%d\t",queue_arr[i]);
    }

    return 0;
}