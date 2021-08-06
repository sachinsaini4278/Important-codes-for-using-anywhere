//BinaryTree Building and Tree Traversal using recursion.

#include<bits/stdc++.h>
using namespace std;

//define a node of tree
struct node
{
    int data;
    struct node *left;
    struct node *right;
};
//Function to create new node
struct node* createNode(int data);

void PreOrderTraversal(node *root);
void PostOrderTraversal(node *root);
void InOrderTraversal(node *root);

void buildTree();

int main()
{
    buildTree();

}

struct node* createNode(int data)
{
    node* newnode= (struct node*)malloc(sizeof(struct node));
    newnode->data=data;
    newnode->left=newnode->right=NULL;
return newnode;
};
void buildTree()
{
    node* root=createNode(1);
    root->left=createNode(2);
    root->right=createNode(3);
    root->left->left=createNode(4);
    root->left->right=createNode(5);
    root->right->left=createNode(6);
    root->right->right=createNode(7);
    cout<<"Inoder \n";
    InOrderTraversal(root);
    cout<<"\nPreoder \n";
    PreOrderTraversal(root);
    cout<<"\nPostoder \n";
    PostOrderTraversal(root);
}

void PreOrderTraversal(node *root)
{
    if(root!=NULL)
    {
        cout<<(root->data)<<" ";
        PreOrderTraversal(root->left);
        PreOrderTraversal(root->right);
    }
}
void InOrderTraversal(node *root)
{
    if(root!=NULL)
    {
        InOrderTraversal(root->left);
        cout<<(root->data)<<" ";
        InOrderTraversal(root->right);
    }
}
void PostOrderTraversal(node *root)
{
    if(root!=NULL)
    {
        PostOrderTraversal(root->left);

        PostOrderTraversal(root->right);
        cout<<(root->data)<<" ";
    }
}
