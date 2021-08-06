
/*
E-->E+E
E-->E*E
E-->id
After removing left recursion It will become
E-->idE'
E'-->+EE'|NULL
E'-->*EE'|NULL

*/
#include<bits/stdc++.h>
using namespace std;
void Eds(); void E();
int i,error=0;
char str[100];
int main()
{
    cout<<"ENTER INPUT"<<endl;
    gets(str); E();
    if(i==strlen(str)&&error==0) cout<<"ACCEPT"<<endl;
    else cout<<"REJECT"<<endl;
}
void E()
{
    if(str[i]=='a')
    {
        i++; Eds();
    }
    else error=1;
}
void Eds()
{
    if(str[i]=='+')
    {
        i++; E(); Eds();
    }
    else if(str[i]=='*')
    {
        i++; E(); Eds();
    }
    else error=1;
}

