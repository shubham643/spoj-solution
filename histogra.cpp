#include<iostream>
#include<stdio.h>
#include<math.h>
#define ll long long
using namespace std;

ll max(ll l,ll r,ll in)
{
	return(l>r?(l>in?l:in):(r>in?r:in));
}

ll findmax(ll *a,ll s,ll e)
{
	if(s==e)
		return(a[s]);
	if(e<s)
		return -1;
	else
	{
		ll mid=(s+e)/2;
		ll left=findmax(a,0,mid);
		ll right=findmax(a,mid+1,e);
		ll intermediate;
        ll save;
        if(a[mid]<a[mid+1])
        	save=a[mid];
        else
        	save=a[mid+1];
        ll i,temp=0;
        for(i=mid+1;i<=e;i++)
        {
        	if(a[i]>=save)
        		temp++;
        	else
        		break;
        }
        for(i=mid;i>=s;i--)
        {
        	if(a[i]>=save)
        		temp++;
        	else
        		break;
        }
        intermediate=temp*save;
        return(max(left,right,intermediate));
	}
}

int main()
{
	ll n;
	while(1)
	{
		scanf("%lld",&n);
		if(n==0)
			return 0;
		ll i,a[n];
		for(i=0;i<n;i++)
			scanf("%lld",&a[i]);
		ll max=findmax(a,0,n-1);
		printf("%lld\n",max);
	}
	return 0;
}