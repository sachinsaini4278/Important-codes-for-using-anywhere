//Merge sort
#include<iostream>
using namespace std;
void merge_process(int [],int,int,int);
void merge_sort(int arr[],int,int);
void print(int[] ,int);
int main()
{
    int n;
    cout<<"Enter the input size\n";
    cin>>n;
    cout<<"Enter the array's element \n";
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    merge_sort(arr,0,n);
    print(arr,n);
    return 0;
}
void merge_sort(int arr[],int beg,int End)
{
    int mid;
    if(beg<End)
    {
        mid=(beg+End)/2;
        merge_sort(arr,beg,mid);
        merge_sort(arr,mid+1,End);
        merge_process(arr,beg,mid,End);
    }
}
void merge_process(int arr[],int beg,int mid,int End)
{
    int i=beg,j=mid+1;
    int temp[100]={0},index=beg;
    while(i<=mid&&j<=End)
    {
        if(arr[i]<arr[j])
        {
            temp[index++]=arr[i++];
        }
        else
        {
            temp[index++]=arr[j++];
        }
    }
    if(i>mid)
    {
        while(j<=End)
        {
            temp[index++]=arr[j++];
        }
    }
    else
    {
        while(i<=mid)
        {
            temp[index++]=arr[i++];
        }
    }
    for(int i=beg;i<index;i++)
    {
        arr[i]=temp[i];
    }
}
void print(int arr[],int n)
{
    for (int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
}
