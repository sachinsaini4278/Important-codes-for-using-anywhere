/*  C program to merge two Sorted linked list */
#include<bits/stdc++.h>
using namespace std;
// first define a structure for a node which has two values. 1st is data and 2nd is pointer of node type which stores the address of another node
struct node
{
    int data;
    struct  node* next;
};
struct node* p=NULL; // Starting point of list 1
struct node* q=NULL; // Starting point of list 2
struct node* mergelist=NULL; // Starting point of merged list

struct node* insertnode(node* ); //Function for insert the node to a linked list
struct node* mergenewlist(node*,node*); //Function for merging the two sorted linked list in sorted order
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
    q=insertnode(q);
    cout<<"P\n";
    display(p);
    cout<<"Q\n";
    display(q);

    mergelist=mergenewlist(p,q);
    cout<<"Merged\n";
    display(mergelist);
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

struct node* mergenewlist(node* p,node* q)
{
        struct node* newlist,*s1;
        if(p->data<q->data)
        {
            newlist=p;
            s1=p;
            cout<<" s->data pif= "<<s1->data<<endl;
            p=p->next;
        }
        else
        {
            newlist=q;
            s1=q;
            cout<<" s->data qif= "<<s1->data<<endl;
            q=q->next;
        }
        while(p!=NULL && q!=NULL)
        {
            if(p->data<q->data)
            {

                s1->next=p;
                //cout<<" s->data p= "<<s1->data<<endl;
                s1=s1->next;
                p=p->next;
            }
            else
            {
                s1->next=q;
                //cout<<" s->data q= "<<s1->data<<endl;
                s1=s1->next;
                q=q->next;
            }
        }

        if(p!=NULL)
        {
            while(p!=NULL)
            {
                s1->next=p;
                s1=s1->next;
                p=p->next;
            }
        }
        else if(q!=NULL)
        {
            while(q!=NULL)
            {
                s1->next=q;
                s1=s1->next;
                q=q->next;
            }
        }

        return newlist;
}
