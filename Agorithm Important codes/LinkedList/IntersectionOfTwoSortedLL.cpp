#include<bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    struct node* next;
};

struct node* resultList=NULL; //Resultant List

void insertNewNode(struct node**,int );  // Function to insert node
/*Double-pointers are used as arguments of function when the function modifies head of the linked list (updates the list) without needing to return the head again,*/

void intersectionTwoSortedLinkedList(struct node*p,struct node*q); //function for performing intersection operation
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
int main()
{
    struct node* p=NULL; //List1
    struct node* q=NULL; //List2
    insertNewNode(&p,6);
    insertNewNode(&p,5);
    insertNewNode(&p,4);
    insertNewNode(&p,3);
    insertNewNode(&p,1);

    insertNewNode(&q,8);
    insertNewNode(&q,6);
    insertNewNode(&q,4);
    insertNewNode(&q,3);

    cout<<"List 1 Data ---------- \n";
    printList(p);
    cout<<"\nList 2 Data ---------- \n";
    printList(q);
    cout<<"\nIntersection of two linkedlist\n";
    intersectionTwoSortedLinkedList(p,q);
    printList(resultList);




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
void intersectionTwoSortedLinkedList(struct node* p,struct node*q)
{
    struct node* tail, *a,*b;
    a=p;
    b=q;
    tail=resultList;
    while(a!=NULL && b!=NULL)
    {
        if(a->data<b->data)
        {
            a=a->next;
        }
        else if(a->data>b->data)
        {
            b=b->next;
        }
        else
        {
            struct node* NewNode=(struct node*)malloc(sizeof(struct node));
            NewNode->data=a->data;
            if(resultList==NULL)
            {
                resultList=NewNode;
                tail=resultList;
            }
            else
            {
                tail->next=NewNode;
                tail=tail->next;
                a=a->next;
                b=b->next;
            }
        }
    }
};
