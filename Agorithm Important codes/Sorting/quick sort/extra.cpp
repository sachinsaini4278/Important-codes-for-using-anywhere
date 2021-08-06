//Largest Sum Contiguous Subarray
//Kadane's Algorithm
#include<bits/stdc++.h>
using namespace std;
int find_max_subarray_sum(int arr[],int n)
{
    int curr_max=arr[0]; // variable that stores the current maximum sum
    int maxm=arr[0]; //variable that stores the final maximum value
    for(int i=1;i<n;i++) //loop starts from 1st index not 0th because first element is taken as max and current max
    {
        curr_max=max(arr[i],curr_max+arr[i]);
        //find the max among arr[i] and current_max + arr[i] because if current max value is less than arr[i] that means it will decrease the
        //value of arr[i] so ignore previous elements and start current max from arr[i]


        maxm=max(maxm,curr_max);
        //find max among current_max and max
    }
    return maxm; //return the final max variable which is maxm
}
int main()
{
    int n; //n is size of array
    cout<<"Enter the total number of elements in array \n";
    cin>>n;
    int arr[n]; //efficient way to give the size of array
    cout<<"Enter the elements of array \n");
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    cout<<"Maximum sum of sub-array is : "<<find_max_subarray_sum(arr,n)<<endl;
}
