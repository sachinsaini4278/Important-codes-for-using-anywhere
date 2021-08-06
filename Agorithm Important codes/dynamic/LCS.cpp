#include<bits/stdc++.h>
using namespace std;
int LongestCommonSunsequence(string,string);
int main()
{
    string str1,str2;
    cout<<"Enter the first string "<<endl;
    cin>>str1;
    cout<<"Enter the second string "<<endl;
    cin>>str2;
    cout<<LongestCommonSunsequence(str1,str2)<<endl;

}
int LongestCommonSunsequence(string str1,string str2)
{
    int len1=str1.length();
    int len2=str2.length();
    int lcs[len1+1][len2+1];
    lcs[0][0]=0;
    for(int i=0;i<=len1;i++)
    {
        for(int j=0;j<=len2;j++)
        {
            if(i==0||j==0)
            {
                lcs[i][j]=0;
            }
            else if(str1[i]==str2[j])
            {
                lcs[i][j]=1+lcs[i-1][j-1];
            }
            else
            {
                lcs[i][j]=max(lcs[i-1][j],lcs[i][j-1]);
            }
        }
    }
    return lcs[len1][len2];
}
