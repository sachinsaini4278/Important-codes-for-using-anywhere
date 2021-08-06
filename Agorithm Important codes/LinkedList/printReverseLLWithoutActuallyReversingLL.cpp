/*
************************Print reverse of a Linked List without actually reversing ******************************

Given a linked list, print reverse of it using a recursive function.
For example, if the given linked list is 1->2->3->4, then output should be 4->3->2->1
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
void printReverseLinkedList(struct node*);
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
    cout<<"Reversed list\n";
    printReverseLinkedList(p);

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
void printReverseLinkedList(struct node* l)
{
    if(l==NULL)
        return;
    printReverseLinkedList(l->next);
    cout<<l->data<<" ";
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
