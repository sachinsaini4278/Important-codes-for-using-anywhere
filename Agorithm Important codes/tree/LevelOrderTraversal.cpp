#include<bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    struct node* left;
    struct node* right;
};
void buildTree();
node* createNode(int);
void levelOrderTraversal(node *root);
int main()
{
    buildTree();
}
void buildTree()
{
    node* root=createNode(1);
    root->left=createNode(2);
    root->right=createNode(3);
    root->left->left=createNode(4);
    root->left->right=createNode(5);
    root->right->left=createNode(6);
    root->right->right=createNode(7);

    levelOrderTraversal(root);

}
node* createNode(int data)
{
    node* newNode=(struct node*)malloc(sizeof(struct node));
    newNode->data=data;
    newNode->left=newNode->right=NULL;
    return newNode;
}

void levelOrderTraversal(node *root)
{
    if(root==NULL)
        return;
    queue<node *>q;
    q.push(root);
    while(q.empty()==false)
    {
        node* x=q.front();
        cout<<x->data<<" ";
        q.pop();

        //Enqueue left child
        if(x->left!=NULL)
            q.push(x->left);
        //Enqueue right child
        if(x->left!=NULL)
            q.push(x->right);

    }

}
