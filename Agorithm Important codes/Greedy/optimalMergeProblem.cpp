//Optimal merge pattern problem
#include<iostream>
using namespace std;
int size=0;  //Defined size globally as we are deleting and inserting the element so size will be changed

//Heapify function
void heapify(int arr[],int parent)
{
    int min=parent;
    int leftChild=2*parent+1;
    int rightChild=2*parent+2;
    if(leftChild<size && arr[min]>arr[leftChild])
    {
        min=leftChild;
    }
    if(rightChild<size && arr[min]>arr[rightChild])
    {
        min=rightChild;
    }
    if(min!=parent)
    {
        swap(arr[min],arr[parent]);
        heapify(arr,min);
    }
}
//Building Heap
void build_heap(int arr[])
{
    for(int i=(size-1)/2;i>=0;i--)
    {
        heapify(arr,i);
    }
}
//For printing array's element
void print(int arr[],int size)
{
    for(int i=0;i<size;i++)
    {
        cout<<arr[i]<<" ";
    }
}
//Insert into heap
void insertIntoHeap(int arr[],int element)
{
    size++;
    arr[size-1]=element;
   // cout<<"\n Helllo \n";
    //print(arr,size);
    build_heap(arr);
}
int OptimalMerge(int arr[])
{
    //var for count two
    int count=size,var=0,temp=0,temp2=0,sum=0;
    while(size!=1)
    {
        temp=arr[0];
        swap(arr[0],arr[size-1]);
        size--;
        heapify(arr,0);

        temp2=arr[0];
        swap(arr[0],arr[size-1]);
        size--;
        heapify(arr,0);
        int a=(temp+temp2);
        cout<<"Temp1="<<temp<<" Temp2="<<temp2<<endl;
        cout<<"a="<<a<<endl;
        insertIntoHeap(arr,a);
        print(arr,size);
        cout<<endl;
        sum+=a;
    }
    return sum;
}
int main()
{
    size=4;
    int arr[10]={4,3,2,6};
    //print(arr,size);
    build_heap(arr);
    cout<<endl;
    //cout<<"size="<<size<<endl;
    print(arr,size);
    //insertIntoHeap(arr,1);
    //cout<<"size="<<size<<endl;
    //cout<<endl;
    //print(arr,size);
    cout<<endl;
int    ans=OptimalMerge(arr);
    cout<<"Ans="<<ans;


}
