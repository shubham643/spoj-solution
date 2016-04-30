#include<iostream>
#include<stdio.h>
#include<math.h>
#define ll long long
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--){
    ll n;
    int i;
    scanf("%lld",&n);
    ll sum=n;
    ll b=sqrt(n);
    for(i=2;i<=b;i++)
    {
    	sum+=i-1;
    	if(n/i>b)
    		sum+=n/i-b;
    }
    printf("%lld\n",sum);
	}
    return 0;
}
