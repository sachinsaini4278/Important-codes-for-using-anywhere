#include<bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    struct node* next;
};
struct node* start=NULL;
void insertNode(int);
void traverse();
int main()
{
    insertNode(31);
    insertNode(31);
    insertNode(34);
    insertNode(3);
    insertNode(31);
    insertNode(2);
    insertNode(21);
    insertNode(21);
    traverse();
}
void insertNode(int data)
{
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=data;
    newnode->next=start;
    start=newnode;
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
