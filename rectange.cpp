#include<iostream>
#include<stdio.h>
#include<math.h>
#define ll long long
using namespace std;

int main()
{
    ll n;
    ll i;
    ll sum=0;
    scanf("%lld",&n);
    ll total=n*(n+1)/2;
    for(i=1;i<n;i++)
    {
        sum+=i*(total-(i*(i-1)/2));
    }
    ll ways=pow(n,2);
    sum+=ways;
  //  cout<<sum<<" "<<ways;
    if(sum%ways==0)
        printf("%lld",sum/ways);
    else
        printf("%lld",sum/ways+1);
    return 0;
}
