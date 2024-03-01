#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 10

int top=-1;
char stack[MAX];
int match_char(char a,char b)
{
    if(a=='[' && b==']')
    return 1;
    if(a=='{' && b='}')
    return 1;
    if(a=='(' && b==')')
    return 1;

    return 0;
}

int check_balanced(char* s)
{
    int i;
    for(i=0;i<strlen(s);i++)
    {
        if(s[i]='[' || s[i]='{' || s[i]='(')
        push(s[i]);

        if(s[i]=']' || s[i]='}' || s[i]=')')
        {
            if(isEmpty())
            {
                printf("Right brackets are more than the left \n ");
                return 0;
            }
            else{
                temp=pop();
                if(!match_char(temp,s[i]))
                {
                    printf("mismatched brackets.\n");
                    return 0;
                }

            }

        }
    }
    if(isEmpty())
    {
        printf("Brakets are well balanced.\n");
        return 1;
    }
    else{
        printf("Left brakets are more than the right.\n");
        return 0;
    }

}

int main()
{
    char expr[MAX];
    int balance;
    printf("Enter the algebraic expression");
    gets(expr);

    balance=check_balance(expr);

    return 0;

}