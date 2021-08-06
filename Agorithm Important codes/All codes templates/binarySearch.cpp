#include <bits/stdc++.h>
#define ll long long
#define f(i,a,b) for(int i=a;i<b;i++)
#define fe(i,a,b) for(int i=a;i<=b;i++)
using namespace std;

int main() {
    ll t;
    cin>>t;
    while(t--)
    {
      ll n,k,b,c,m;
      ll ans=0,flag=0,result=0,sum=0,temp=0;
      ll counter=0,counter1=0,counter2=0;
      ll arr[100005];
      int result = binarySearch(arr, 0, n - 1, x);
      (result == -1) ? printf("Element is not present in array")
				: printf("Element is present at index %d",
							result);

    }
	return 0;
}
int binarySearch(int arr[], int l, int r, int x)
{
	if (r >= l) {
		int mid = l + (r - l) / 2;

		// If the element is present at the middle
		// itself
		if (arr[mid] == x)
			return mid;

		// If element is smaller than mid, then
		// it can only be present in left subarray
		if (arr[mid] > x)
			return binarySearch(arr, l, mid - 1, x);

		// Else the element can only be present
		// in right subarray
		return binarySearch(arr, mid + 1, r, x);
	}

	// We reach here when element is not
	// present in array
	return -1;
}

