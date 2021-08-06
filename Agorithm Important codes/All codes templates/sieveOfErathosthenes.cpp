#include<bits/stdc++.h>
using namespace std;
long sieve[1000001]={0};//Sieve array ,will store the the prime numbers
void fillsieve(void); //function that will fill the array with corresponding index
void applysieve(void); //apply the sieve of Erathosthenes
void printsieve(void);
int main()
{
    fillsieve();
    applysieve();
    printsieve();
}
void fillsieve(void)
{
    long i;
    for(i=0;i<1000001;i++)
    {
        sieve[i]=i;
    }
}
void applysieve(void)
{
    long i=0,limit,prime,multiple,j=0;
    limit=sqrt(1000000);
    sieve[0]=sieve[1]=-1;
    for(i=0;i<limit;i++)
    {
        if(sieve[i]!=-1)
        {
            prime=sieve[i];
            j=2;
            while(prime*j<=1000000)
            {
                sieve[prime*j]=-1;
                j++;
            }
        }
    }

}
void printsieve(void)
{
    long i=0,count=0,ans=0;
    for(i=0;i<200;i++)
    {
        if(sieve[i]!=-1)
        {
            cout<<sieve[i]<<" ";
        }
    }
}
