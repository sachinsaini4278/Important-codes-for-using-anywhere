//Use Two pointers move one to one step ahead and second
//to two step ahead so first pointer will be on the position of middle node
#include<bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    struct  node* next;
};
struct node* p=NULL; // Starting point of list 1
struct node* insertnode(node* ); //Function for insert the node to a linked list
void DeleteMiddleOfLL(struct node*);
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
    DeleteMiddleOfLL(p);

}
struct node* insertnode(struct node* s)
{
    int n;
    cout<<"How many node you want to insert : "<<endl;
    cin>>n;
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
void DeleteMiddleOfLL(struct node* start)
{
    struct node *ptr1,*ptr2,*preptr;
    ptr1=ptr2=start;
    while(ptr2!=NULL && ptr2->next!=NULL)
    {
        preptr=ptr1;
        ptr1=ptr1->next;
        ptr2=ptr2->next->next;
    }
    preptr->next=ptr1->next;
    display(start);
}
