#include<stdio.h>
#include<stdlib.h>

struct node{
    struct node* prev;
    int data;
    struct node* next;
};

//insertion in an empty list
struct node* add_to_empty(struct node* head,int data){
struct node* temp= malloc(sizeof(struct node));
temp->prev=NULL;
temp->data=data;
temp->next=NULL;
head=temp;
return head;
}

//adding a node in head position
struct node* add_at_beg(struct node* head,int val)
{
    struct node* new =malloc(sizeof(struct node));
    new->prev=NULL;
    new->data=val;
    new->next=NULL;

    new->next=head;
    head->prev=new;

    head=new;
    return head;
}

// insertion of a node at the end of the list
void add_at_end(struct node* head,int val)
{
    struct node* new=malloc(sizeof(struct node));
    new->prev=NULL;
    new->data=val;
    new->next=NULL;

    struct node* temp=NULL;
    temp=head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=new;
    new->prev=temp;
}

//insertion of a node  at a certain  position
struct node* add_at_pos(struct node* head,int data,int pos)
{
   struct node* new=NULL;
   struct node* temp=head;
   struct node* temp2=NULL;

   new=add_to_empty(new,data);


    while(pos!=1)
    {
        temp=temp->next;
        pos--;

    }
    temp2=temp->next;
    temp->next=new;
    new->prev=temp;
    new->next=temp2;
    temp2->prev=new;

    //for the end of the list
    if(temp->next==NULL)
    {
        temp->next=new;
        new->prev=temp;
    }

 return head;


}

//deleting the last node
void del_last(struct node* head)
{
    struct node* temp=NULL;
    struct node* temp2=NULL;
    temp=head;
    while(temp->next!=NULL)
    {
        temp2=temp;
        temp=temp->next;
    }
    temp2->next=NULL;
    temp->prev=NULL;
    free(temp);
    temp=NULL;
}

//deleting the 1st node
struct node* del_first(struct node* head)
{
    struct node* temp=NULL;
    temp=head;
    head=head->next;
    free(temp);
    temp=NULL;
    head->prev=NULL;
    return head;
}

//deletion of a node of a certain position
struct node* del_pos(struct node* head,int position)
{
    struct node* temp=head;
    struct node* temp2=NULL;
    if (position == 1)
    {
        head=delfirst(head);
        return head;
    }
    while(position > 1)
    {
        temp=temp->next;
        position--;
    }
    if(temp->next==NULL)
      head=del_last(head);
    else{
        temp2=temp->prev;
        temp2->next=temp->next;
        temp->next->prev=temp2;
        free(temp);
        temp=NULL;
    }
    return head;
}

//creating a hole list
struct node* create_list(struct node* head)
{
    int n,data,i;
    printf("Enter the no.of nodes");
    scanf("%d",&n);

    if(n==0)
    return head;

    printf("Enter the element for thr node 1:");
    scanf("%d",&data);
    head=add_to_empty(head,data);

    for(i=0;i<n;i++)
    {
        printf("Enter the element for the node :%d",i+1);
        scanf("%d",&data);
        add_at_end(head,data);

    }
    return head;
}


int main()
{
    //creating a node
    struct node* head=malloc(sizeof(struct node));
    /*head->prev=NULL;
    head->data=45;
    head->next=NULL;
    */
   head=add_to_empty(head,45);
   add_at_end(head,10);
   add_at_end(head,8);
   add_at_end(head,7);

   head=del_first(head);

   struct node *print=NULL;
   print=head;
   while(print!=NULL)
   {
    printf("%d\t",print->data);
    print=print->next;
   }

    return 0;
}