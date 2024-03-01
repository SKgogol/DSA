#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* next;
};
//node of the circular singly linked list
struct node* circularSingly(int data)
{
  struct node* temp=malloc(sizeof(struct node ));
  temp->data=data;
  temp->next=temp;
  return temp;
}

//insertion of a node in the beginning of the list
struct node* add_at_beg(struct node* tail,int data)
{
struct node* newp=malloc(sizeof(struct node));
newp->data=data;
newp->next=tail->next;
tail->next=newp;
return tail;

}
//insertion of a node in the end of a list
struct node* add_at_end(struct node* tail,int data)
{
    struct node* newp=mallloc(sizeof(struct node));
    newp->data=data;
    newp->next=NULL;

    newp->next=tail->next;
    tail->next=newp;
    tail=tail->next;
    return tail;
}
//insertion a new node at an certain position
struct vode* add_certain(struct node* tail,int pos ,int data)
{
    struct node* newp=malloc(sizeof(struct node));

    newp->data=data;
    newp->next=NULL;

    while (pos>1)
    {
        p=p->next;
        pos--;
    }
    newp->next=p->next;
    p->next=newp;

    if(p==tail)
    {
    tail=tail->next;
    }

    return tail;
}

//deletion of first node
struct node* del_first(struct node* tail)
{
    if(tail==NULL)
       return tail;

    if(tail->next==tail)
    {
        free(tail);
        tail=NULL;
        return tail;
    }
    struct node* temp=tail->next;
    tail->next=temp->next;
    free(temp);
    temp=NULL;
    return tail;
}
//deletion of the last node
struct node* del_last(struct node* tail)
{
    if(tail==NULL)
       return tail;
   struct node* temp=tail->next;
   if(temp->next==tail)
   {
     free(tail);
     tail=NULL;
     return tail;
   }
   while(temp->next!=tail)
   {
    temp=temp->next;
   }
   temp->next=tail->next;
   free(temp);
   temp=NULL;
   return tail;

}
//deletion of the ceratin node
struct node* del_certain(struct node* tail,int pos)
{
    if(tail==NULL)
    {
        return tail;
    }
    struct node* temp=tail->next;
    if(tail->next==tail)
    {
        free(tail);
        tail=NULL;
        return tail;
    }
    while(pos>2)
    {
        temp=temp->next;
        pos--;
    }
     struct node* temp2=tail->next;
     temp->next=temp2->next;
     //Handling the case of deleting the last node
     if(temp2==tail)
     {
        tail=temp;
     }
     free(temp2);
     temp2=NULL;

}
//count the number of elements
void count_node(struct node* tail)
{
    struct node* temp=tail->text;
     int count=0;
    while(temp!=tail)
    {
        count++;
        temp=temp->next;

    }
    count++;
}
//searching in the list
int searchelement(struct node* tail,int element)
{
    struct node* temp;
    int index=0;

    if(tail==NULL)
       return -2;

    temp=tail->next;
    do{
        if(temp->data==element)
         return index;
        temp=temp->next;
        index++;

    }
    while(temp!=tail->next);
    return -1;

}

void print(struct node* tail)
{
    struct node* p=tail->next;
    do{
        printf("%d",p->data);
        p=p->next;
    }
    while(p!=tail->next);
}



int main()
{
    int data;
    struct node* tail;
    tail=circularSingly(data);

    printf("%d\n",tail->data);
    return 0;
}