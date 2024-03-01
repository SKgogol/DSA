#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node* next;

    node(int val)
    {
        data=val;
        next=NULL;
    }
};

void insert(node* &head,int val)
{
    //creating a new node
    node* n=new node(val);

    //itarating to the last node
    node* temp=head;
    while(temp->next!=0)
    {
        temp=temp->next;
    }

    //storing the new node to the position
    temp->next=n;
}

void display(node* head)
{
    node* temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
    }

}


int main()
{

}