#include<bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    struct  node* next;
};

struct node* start=NULL; // Starting point of list 1
struct node* insertnode(node* ); //Function for insert the node to a linked list
int countNodesInLoop(struct node*);
void insert_at_position(int data, int pos);
void DetectLoop(struct node*);
//Function for printing the list

void traverse()
{
    struct node* ptr=start;
    do
    {
        cout<<ptr->data<<" ";
        ptr=ptr->next;
    }while(ptr!=NULL);
    cout<<endl;
}


int main()
{
    insert_at_position(4,1);
    insert_at_position(12,1);
    insert_at_position(1,2);
    insert_at_position(14,2);
    traverse();
    struct node* ptr=start;
    ptr=ptr->next->next->next;
    ptr->next = ptr;
    //ptr=ptr->next;
    //cout<<"PTR_DATSa"<<ptr->data<<" ";

    DetectLoop(start);
}
void DetectLoop(struct node* ptr)
{
       struct node* p,*q;
       p=q=start;
       int flag=0;
       while(p && q && (q->next))
       {
           p=p->next;
           q=q->next->next;
           if(p==q)
           {
                flag=1;
                cout<<countNodesInLoop(p);
                break;
           }

       }
       if(flag==0)
       {
           cout<<"No LOOP \n";
       }
}
void insert_at_position(int data, int pos)
{
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=data;
    newnode->next=NULL;
    int counter=0;
    if(start==NULL)
    {
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

int countNodesInLoop(struct node* p)
{
    cout<<" enddddddddddddddddddd \n";
    int nodesCount=0;
    struct node* ptr=p;
    while(ptr->next!=p)
    {
        cout<<ptr->data<<" ";
        nodesCount++;
        ptr=ptr->next;
    }
     cout<<" enddddddddddddddddddd \n";
    return nodesCount+1;
}
