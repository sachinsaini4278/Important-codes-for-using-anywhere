//Insertion sort
#include<iostream>
using namespace std;
int insertion_sort(int [],int);//Insertion sort function
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
    insertion_sort(arr,total_elements);//calling bubble_sort function
    printArray(arr,total_elements);//calling print function which will print array
    return 0;
}
int insertion_sort(int arr[],int n)
{
    int j,temp=0;
    for(int i=0;i<n;i++)
    {
        temp=arr[i];//copy the i_th element in temp and compare back until find its correct position
        j=i-1; //take j as previous index of i
        while(temp<arr[j]&&j>=0) //compare i'th element with j'th and put j'th element in j+1'th position
        {
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=temp;//when condition false then j is on one previous position because of condition checking so put the temp in correct position which is j+1'th index
    }
}
int printArray(int arr[],int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
}
