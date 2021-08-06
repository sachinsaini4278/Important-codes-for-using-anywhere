#include <bits/stdc++.h>
using namespace std;
void fillFrequencyArray(string str,int freq[])
{
    for(int i=0;i<str.length();i++)
    {
        int index=str[i]-'a';
        freq[index]++;
    }
}
void print(int arr[],int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string str;
        cin>>str;
        int freq[26]={0};
        fillFrequencyArray(str,freq);
        printarray(freq,26);
    }
	return 0;
}

