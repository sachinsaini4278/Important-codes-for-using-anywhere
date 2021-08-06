#include<bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    struct node* next;
};
struct node* start=NULL;
void insert_at_begining(int);
void insert_at_end(int);
void insert_at_position(int , int );
void traverse();
int main()
{
    //insert_at_begining(4);
    //insert_at_end(6);
    insert_at_position(4,1);
    traverse();
    //insert_at_begining(3);
    //insert_at_end(12);
    insert_at_position(12,1);
    traverse();
    //insert_at_begining(2);
    //insert_at_end(14);
    insert_at_position(1,2);
    traverse();
    //insert_at_begining(16);
    //insert_at_end(4);
    insert_at_position(14,2);
    traverse();
}
void insert_at_position(int data, int pos)
{
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=data;
    newnode->next=NULL;
    int counter=0;
    if(start==NULL)
    {
        newnode->next=NULL;
        start=newnode;
    }
    else
    {
        struct node* ptr=start;
        while(counter<pos-1)
        {
            counter++;
            ptr=ptr->next;
        }
        newnode->next=ptr->next;
        ptr->next=newnode;
    }
}
void insert_at_begining(int data)
{
    //this is for creating a node by allocating the memory.
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=data;
    if(start==NULL)
    {
        newnode->next=NULL;
        start=newnode;
    }
    else
    {
        newnode->next=start;
        start=newnode;
    }
}
void insert_at_end(int data)
{
    //this is for creating a node by allocating the memory.
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=data;
    if(start==NULL)
    {
        newnode->next=NULL;
        start=newnode;
    }
    else
    {
        struct node* ptr=start;
        while(ptr->next!=NULL)
        {
            ptr=ptr->next;
        }
        ptr->next = newnode;
        newnode->next=NULL;
    }
}
void traverse()
{
    struct node* ptr=start;
    while(ptr!=NULL)
    {
        cout<<ptr->data<<" ";
        ptr=ptr->next;
    }
    cout<<endl;
}
