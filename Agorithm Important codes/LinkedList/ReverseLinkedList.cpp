/*  C program to Reverse a linked list */
#include<bits/stdc++.h>
using namespace std;
// first define a structure for a node which has two values. 1st is data and 2nd is pointer of node type which stores the address of another node
struct node
{
    int data;
    struct  node* next;
};
struct node* p=NULL; // Starting point of list 1
struct node* revList=NULL; // To store the pointer of reversed List
struct node* reverseList(node*); //Function to Reverse a list
struct node* insertnode(node* ); //Function for insert the node to a linked list
//Function for printing the list
void display(node* s)
{
    //ptr is temporary pointer which is created for traversing the list
    struct node* ptr=s; //Initially it will equal to list which is passed to the function
    while(ptr!=NULL)
    {
        cout<<ptr->data<<" ";
        ptr=ptr->next;
    }
    cout<<endl;
}
int main()
{
    //create the two linked list
    p=insertnode(p);
    cout<<"P\n";
    display(p);
    cout<<"reversed list \n"<<endl;
    revList=reverseList(p);
    display(revList);

}
struct node* insertnode(struct node* s)
{
    int n;
    cout<<"How many node you want to insert : "<<endl;
    cin>>n;
    cout<<"Enter data in sorted order :"<<endl;
    while(n--)
    {
        int data=0;
        cout<<"Enter data "<<endl;
        cin>>data;
        struct node* newnode=(struct node*)malloc(sizeof(node));//
        newnode->data=data;
        newnode->next=NULL;
        if(s==NULL)
        {
            s=newnode;
        }
        else
        {
            struct node* ptr=s;
            while(ptr->next!=NULL)
            {
                ptr=ptr->next;
            }
            ptr->next=newnode;
        }
    }
    return s;
}
//Function for reversing a linked list
struct node* reverseList(node* s)
{
    //Take three pointers previous , current and next of structure type
    struct node *prev=NULL,*curr=s,*next=NULL;
    while(curr!=NULL)
    {
        next=curr->next; //move next pointer to one ahead
        curr->next=prev; //now change the next linked pointer to previous node
        prev=curr; //as linked is connected to previous node so move prev pointer to one ahead
        curr=next; // and curr to next
    }
    s=prev; //Finally change the head to the prev as prev reached to the last node
    return s; //return list

};
