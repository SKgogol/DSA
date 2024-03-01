#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* link;

};

//counting of nodes
void count_of_nodes(struct node* head)
{
    int count=0;
    if(head==NULL)
    {
        printf("Linked list is empty");
    }
    struct node* ptr=NULL;
    ptr=head;
    while(ptr!=NULL)
    {
        count++;
        ptr=ptr->link;
    }
    printf("%d",count);

}

//printing all the data of linked list
void printing_data(struct node* head)
{
    if(head==NULL)
    {
    printf("Linked list is empty");
    }

    struct node* ptr=NULL;
    ptr=head;
    while(ptr!=NULL)
    {
        printf("%d\t",ptr->data);
        ptr=ptr->link;

    }
}

//inserting a element at the end position
void add_in_end(struct node *head,int val)
{

    struct node* new=malloc(sizeof(struct node));
    new->data=val;
    new->link=NULL;

    struct node* ptr=NULL;
    ptr=head;
    while(ptr->link!=NULL)
    {
       ptr=ptr->link;

    }
    ptr->link=new;
}

//inserting an element in the head position by returning the head
struct node* add_in_front(struct node* head,int val)
{
    struct node* new_head=malloc(sizeof(struct node));
    new_head->data=val;
    new_head->link=head;
    head=new_head;
    return head;
}

//inserting an element in the head posi without returning the head
void add_in_beg(struct node **head,int val)
{
    struct node *new=malloc(sizeof(struct node));
    new->data;
    new->link=NULL;

    new->link=*head;
    head=new;

}

//inserting a new node in a certain position
void add_in_pos(struct node* head,int data,int pos)
{
    struct node* ptr=head;
    struct node* new_node=malloc(sizeof(struct node));
    new_node->data=data;
    new_node->link=NULL;

    //now we need to traverse to the given position
    pos--;
    while(pos!=1)
    {
        ptr=ptr->link;
        pos--;

    }
    new_node->link=ptr->link;
    ptr->link=new_node;


}

//deletion of first node
struct node* del_first(struct node* head)
{
    if(head==NULL)
    {
        printf("List is already empty");
    }
    else{
        struct node* temp=head;
        head=head->link;
        free(temp);
        temp=NULL;
    }
    return head;
}

//deletion of the last node of a linked list
struct node* del_last(struct node* head)
{
    struct node* temp=head;
    struct node* temp2=head;
    if(head==NULL)
    {
        printf("List is empty");
    }
    else if (head->link==NULL)
    {
        free(head);
        head=NULL;
    }
    else{
        while(temp->link!=NULL)
        {
            temp2=temp;
            temp=temp->link;
        }
        temp2->link=NULL;
        free(temp);
        temp=NULL;
    }
    return head;

}

//deletion of a node from a certain position
void del_pos(struct node** head,int pos)
{
    struct node* previous=*head;
    struct node* current =*head;

    if(*head==NULL)
    {
        printf("List is empty");

    }

    else if(pos==1)
    {
      *head=current->link;
      free(current);
      current=NULL;
    }

    else{
        while(pos!=1)
        {
            previous=current;
            current=current->link;
            pos--;
        }
        previous->link=current->link;
        free(current);
        current=NULL;
    }
}

//deletion of the entire linked list
void del_entirelist(struct node *head)
{
    struct node *temp=head;
    while(temp!=NULL)
    {
        temp=temp->link;
        free(head);
        head=temp;
    }
}

//reverse a linked list
struct node* reverse(struct node *head)
{
    struct node *prev=NULL;
    struct node *next=NULL;

    while(head!=NULL)
    {
        next=head->link;
        head->link=prev;
        prev=head;
        head=next;
    }
    head=prev;
    return head;

}

int main()
{
    //adding the 1st head node
    struct node *head=NULL;
    head=malloc(sizeof(struct node));
    head->data=4;


    struct node *second=malloc(sizeof(struct node));
    second->data=5;
    second->link=NULL;
    head->link=second;


   // head=add_in_front(head,8);
   //add_in_beg(&head,8);

   //head=del_first(head);
    printing_data(head);


    return 0;



}