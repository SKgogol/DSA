#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* link;
}
*top=NULL;//declaring the top pointer globally

int isEmpty()
{
    if(top==NULL)
    return 1;
    else
    return 0;
}


void  push(int val)
{
    struct node* new_node=malloc(sizeof(struct node));
    new_node->data=val;
    new_node->link=NULL;

    if(new_node==NULL)
    //malloc() function  returns NULL when the requested memory cant be allocated.
    {
      printf("Stack Overflow");
      exit(1);
    }
    new_node->link=top;
    top=new_node;

}

int pop()
{
    struct node* temp=NULL;
    temp=top;
    int val;
    val=temp->data;

    top=top->link;
    free(temp);
    temp=NULL;

    return val;


}

int peek()
{
    if(isEmpty())
    {
        printf("Stack Underflow");
        exit(1);
    }
    return top->data; 
}

void print()
{
    struct node* temp;
    temp=top;
    if(isEmpty())
    {
        printf("Stack Underflow");
        exit(1);
    }
    printf("The stack elements are: ");
    while(temp)
    {
      printf("%d",temp->data);
      temp=temp->link;
    }
    printf("\n");
}



int main()
{
    int choice,data;
    while(1)
    {
        printf("1.Push\n");
        printf("2.Pop\n");
        printf("3.print\n");
        printf("4.quit\n");
        printf("Enter the choice: ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
               printf("enter the element to be pushed:");
               scanf("%d",&data);
               push(data);
               break;
            case 2:
                data=pop();
                printf("Deleted element is %d\n,data");
                break
               break;
            case 3:
               print();
               break;
            case 4:
                exit(1);
            default:
               printf("Wrong Choice");
               break;
        }
    }
   return 0;
}