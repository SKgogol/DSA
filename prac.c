#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *link;
};

struct node *add_in_head(struct node **head,int val)
{
    struct node *new_node=malloc(sizeof(struct node));
    new_node->data=val;
    new_node->link=head;

    head=new_node;
    return head;


}

void add_at_end(struct node *head,int val)
{
    struct node* new_node=malloc(sizeof(struct node ));
    new_node->data=val;
    new_node->link=NULL;

    struct node* ptr=NULL;
    



}

int main()
{
    struct node *head=malloc(sizeof(struct node));
    head->data=23;
    head->link=NULL;

    struct node *current=malloc(sizeof(struct node));
    current->data=34;
    current->link=NULL;
    head->link=current;

}