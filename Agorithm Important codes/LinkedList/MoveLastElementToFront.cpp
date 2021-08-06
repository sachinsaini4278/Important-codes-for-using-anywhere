/*
Move last element to front of a given Linked List

Write a function that moves the last element to the front in a given Singly Linked List.
For example, if the given Linked List is 1->2->3->4->5, then the function should change the list
to 5->1->2->3->4.
*/
#include<bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    struct node* next;
};

void insertNewNode(struct node**,int );  // Function to insert node
/*Double-pointers are used as arguments of function when the function
modifies head of the linked list (updates the list) without needing to return the head again,*/
void printList(struct node* l);
void moveLastElementToFront(struct node**);
int main()
{
    struct node* p=NULL; //List1

    insertNewNode(&p,6);
    insertNewNode(&p,5);
    insertNewNode(&p,4);
    insertNewNode(&p,3);
    insertNewNode(&p,1);

    cout<<"Original List  Data ---------- \n";
    printList(p);
    moveLastElementToFront(&p);
    cout<<"List  Data After moved---------- \n";
    printList(p);




}
void insertNewNode(struct node** l,int data)
{
    struct node* newNode;
    newNode=(struct node*)malloc(sizeof (struct node));
    newNode->data=data;
    newNode->next=(*l);
    (*l)=newNode;
    //cout<<l->data;
}
void moveLastElementToFront(struct node** l)
{
    struct node* ptr = (*l) ,*preptr;
    //ptr will reached to the last node and preptr will be at second last node
    while(ptr->next!=NULL)
    {
        preptr=ptr;
        ptr=ptr->next;
    }
    ptr->next=(*l);
    (*l)=ptr;
    preptr->next=NULL;


}
void printList(struct node* l)
{
    struct node* ptr=l;
    while(ptr!=NULL)
    {
        cout<<ptr->data<<" ";
        ptr=ptr->next;
    }
    cout<<endl;
}
