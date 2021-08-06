#include<bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    struct node* next;
};
struct node* start=NULL;
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
int SearchElementUsingRecursion(struct node* ptr,int val)
{
    if(ptr==NULL)
    {
        return 0;
    }
    else if(ptr->data==val)
    {
        return 1;
    }
    else
    {
        return SearchElementUsingRecursion(ptr->next,val);
    }
}
int main()
{
    insertNode(5);
    insertNode(23);
    insertNode(12);
    insertNode(13);
    insertNode(25);
    insertNode(28);
    traverse();
    int countt=SearchElementUsingRecursion(start,1);
    if(countt)
    {
        cout<<"Yes\n";
    }
    else
    {
        cout<<"No\n";
    }
}
