#include<stdio.h>
#include<stdlib.h>
#define MAX 4

int stack_arr[MAX];
int top=-1;
int isFUll()
{
    if(top==MAX-1)
    return 1;
    else
    return 0;
}
int isEmpty()
{
    if(top==-1)
    return 1;
    else
    return 0;
}
void push(int data)
{
    if(top==MAX-1)//if(isFull())
    {
        printf("Stack Overflow");
        return;
    }
    top=top+1;
    stack_arr[top]=data;
}
int  pop()
{
    if(top==-1)//if(isEmpty())
    {
        printf("Stack is Empty");
        exit(1);
    }
    int value;
    value=stack_arr[top];
    top=top-1;
    return value;

}
void print()
{
    int i;
    if(top==-1)
    {
        printf("Stack underflow");
        return;
    }
    for(i=top;i>=0;i--)
    {
        printf("%d ",stack_arr[i]);
    }
    printf("/n");

}

int main()
{
    int choice;

    int data;
    while(1)
    {
     printf("PRESS-1:TO PUSH AN ELEMENT");
     printf("PRESS-2:TO POP AN ELEMENT");
     printf("PRESS-3:TO PRINT THE TOP ELEMENT");
     printf("PRESS-4:TO PRINT ALL ELEMENT");
     printf("PRESS-5:QUIT");

     printf("Enter the choice=");
     scanf("%d",&choice);

     switch(choice)
     {
        case 1:
        printf("Enter the element to be pushed:");
        scanf("%d",&data);
        push(data);
        break;
        case 2:
        data=pop();
        printf("Deleted element is %d\n",data);
        break;
        case 3:
        printf("The top element is %d\n",top);
        break;
        case 4:
        print();
        break;
        case 5:
        exit(1);

        default:
        printf("Wrong Choice\n");



     }

     }


    }




    return 0;
}