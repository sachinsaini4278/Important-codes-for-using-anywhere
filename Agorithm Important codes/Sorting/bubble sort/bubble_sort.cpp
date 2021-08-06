//Bubble sort
#include<iostream>
using namespace std;
int bubble_sort(int [],int);//bubble_sort function
int printArray(int [],int);//printing function
int main()
{
    int total_elements=0;
    cout<<"Enter total no of elements\n";
    cin>>total_elements;
    int arr[total_elements];//create an array of size total elements
    cout<<"Enter "<<total_elements<<" Elements\n";
    for(int i=0;i<total_elements;i++)
    {
        cin>>arr[i]; //Taking elements from user
    }
    bubble_sort(arr,total_elements);//calling bubble_sort function
    printArray(arr,total_elements);//calling print function which will print array
    return 0;
}
int bubble_sort(int arr[],int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if(arr[j]>arr[j+1])
            {
                swap(arr[j],arr[j+1]);
            }
        }
    }
}
int printArray(int arr[],int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
}
