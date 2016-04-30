#include<iostream>
#include<stdio.h>
#include<math.h>
#define ll long long
using namespace std;

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        ll n,val,sum=0;
        cin.ignore();
        scanf("%lld",&n);
        ll i;
        for(i=0;i<n;i++)
        {
            scanf("%lld",&val);
            sum+=val;
            sum%=n;
        }
        cout<<sum;
        if(sum%n==0)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
