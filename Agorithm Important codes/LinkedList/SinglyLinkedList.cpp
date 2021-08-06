#include<bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    struct node* next;
};
struct node* head =NULL;
void printList();
void insert_node(int data,int pos);
void delete_node_by_value(int val);
void delete_node_by_pos(int pos);
void search_node(int data);
struct node* create_node(int data);
int main()
{
    insert_node(4,0);
    printList();
    insert_node(1,1);
    printList();
    insert_node(12,2);
    printList();
    insert_node(4,1);
    printList();
    delete_node_by_value(1);
    printList();

}
struct node* create_node(int data)
{
    struct node* newnode;
    newnode=(struct node*)malloc(sizeof (struct node));
    newnode->data=data;
    newnode->next=NULL;
    return newnode;
}
void insert_node(int data,int pos)
{
    int count=0;
    if(pos==0)
    {
      struct node* newnode= create_node(data);
      head = newnode;
      newnode->next=NULL;
    }
    else
    {
        struct node* newnode= create_node(data);
        struct node*ptr=head;
        while(count<pos-1)
        {
            ptr=ptr->next;
            count++;
        }
        newnode->next=ptr->next;
        ptr->next=newnode;
    }
}
void delete_node_by_value(int val)
{
    struct node* ptr,*preptr;
    ptr=head;
    while(ptr->data!=val)
    {
        preptr=ptr;
        ptr=ptr->next;
    }
    preptr->next=ptr->next;
}
void printList()
{
    struct node* ptr=head;
    while(ptr!=NULL)
    {
        cout<<ptr->data<<" ";
        ptr=ptr->next;
    }
    cout<<endl;
}
