//DFS using Adjacency Matrix
#include<bits/stdc++.h>
using namespace std;
int mat[10][10],source,V,E;
int VisitedArray[30]; //Visited array to store visited elements
void DFS(int i) //Depth first function
{
    VisitedArray[i]=1;
    cout<<i+1<<" "; // to print sequence of visited node as i is visiting every-time
    for(int j=0;j<V;j++)
    {
        if(mat[i][j]==1 && VisitedArray[j]==0)
        {
            DFS(j);
        }
    }
}
void print()
{
    for(int i=0;i<V;i++)
    {
        for(int j=0;j<V;j++)
        {
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
    }
}
int main()
{
    int numOfEdges=0;
    //cout<<"Enter Total Number Of Edges \n";
    //cin>>numOfEdges;
    //createMatrix(numOfEdges);
    mat[0][1]=1;
    mat[1][0]=1;
    mat[0][3]=1;
    mat[3][0]=1;
    mat[3][2]=1;
    mat[2][3]=1;
    mat[1][2]=1;
    mat[2][1]=1;
    mat[1][4]=1;
    mat[4][1]=1;
    mat[1][7]=1;
    mat[7][1]=1;
    mat[6][1]=1;
    mat[1][6]=1;
    mat[4][5]=1;
    mat[5][4]=1;
    mat[4][7]=1;
    mat[7][4]=1;
    mat[4][6]=1;
    mat[6][4]=1;
    mat[6][7]=1;
    mat[7][6]=1;
    mat[2][9]=1;
    mat[9][2]=1;
    mat[2][8]=1;
    mat[8][2]=1;
    V=10;
    print();
    DFS(0);
}
