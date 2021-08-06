//*************Selection sort******************
//Logic -- find smallest element and put on the first then find smallest
// in remaining part excluding first and put on 2nd position then third smallest
// and put on 3rd index and so on until complete array*/
#include<iostream>
using namespace std;
int selection_sort(int [],int);//Selection sort function
int printArray(int [],int);//printing function
int find_smallest(int [],int,int);//Finds the smallest element
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
    selection_sort(arr,total_elements);//calling bubble_sort function
    printArray(arr,total_elements);//calling print function which will print array
    return 0;
}
int selection_sort(int arr[],int n)
{
    for(int i=0;i<n;i++)
    {
        int pos=find_smallest(arr,i,n);
        int temp=arr[i];
        arr[i]=arr[pos];
        arr[pos]=temp;
    }
}
int find_smallest(int arr[],int k,int n)//Finds the smallest element from position to last in array
{
    int position=k;
    int small=arr[k];
    for(int i=k+1;i<n;i++)
    {
        if(arr[i]<small)
        {
            small=arr[i];
            position=i;
        }
    }
    return position;
}
int printArray(int arr[],int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
}
