#include<stdio.h>
#include<stdlib.h>

struct node* circularDoubly(int data);
{
    struct node* temp=malloc(sizeof(struct node));
    temp->data=data;
    temp->next=temp;
    temp->prev=temp;

    return temp;
}

int main()
{
    int data=45;
    struct node* tail;
    tail=circularDoubly(data);

    printf("%d\n",tail->data);
    return 0;
}