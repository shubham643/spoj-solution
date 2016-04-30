#include<iostream>
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string>
#include<string.h>
#include<windows.h>
#define ll long long
using namespace std;

int main()
{
    ll t;
    ll a[21];
    ll i,j=2;
    for(i=1;i<21;i++)
    {
        cout<<i;
        j=2;
        ll temp=pow(i,j);
   /*     if(i==13||i==17)
        {
            a[13]=a[17]=4;
            continue;
        }
    */
        while(temp%10!=i%10)
        {
            j++;
            temp=pow(i,j);
        }
        a[i]=j-1;
    }
    scanf("%lld",&t);
    while(t--)
    {
        ll l;
        ll b;
        scanf("%lld%lld",&l,&b);
        ll rem=b%a[l];
        cout<<rem<<" ";
        ll ll j,temp;
        if(rem==0)
            printf("%lld\n",l%10);
        else{
        for(j=1;j<=rem;j++)
        {
            temp=pow(l,j);
        }
        printf("%lld\n",temp%10);
        }
    }
    return 0;
}
