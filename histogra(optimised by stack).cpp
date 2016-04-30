#include<iostream>
#include<stdio.h>
#include<stack>
#define ll long long
using namespace std;

/*
int main()
{
	ll n;
	while(1)
	{
		scanf("%lld",&n);
		if(n==0)
			return 0;
		ll a[n],s[n],i,temp,save;
		scanf("%lld",&a[0]);
		s[0]=a[0];
		save=a[0];
		temp=a[0];
		ll count;
		count=1;
		for(i=1;i<n;i++)
		{
			scanf("%lld",&a[i]);
			if(a[i]>=s[count-1])
			{
				s[count]=a[i];
				count++;
			}
			else
			{
				ll j=count-1;
				while(j>=0&&s[j]>a[i])
				{
					if(s[j]*(count-j)>save)
						save=s[j]*(count-j);
					if(a[i]*(count-j+1)>save)
						save=a[i]*(count-j+1);
					j--;
				}
				ll last=count;
				count=j+1;
				s[count]=a[i];
				count++;
				while(j>=0)
				{
					if(s[j]*(last-j+1)>save)
						save=s[j]*(last-j+1);
					j--;
				}
			}
		}
		if(count>0)
		{
			ll j=count-1;
			while(j>=0)
			{
				if(s[j]*(count-j)>save)
					save=s[j]*(count-j);
				j--;
			}
		}
		printf("%lld\n",save);
	}
	return 0;
}
*/

ll getMaxArea(ll hist[], ll n)
{
    stack<ll> s;
 
    ll max_area = 0;
    ll tp;
    ll area_with_top; 
    ll i = 0;
    while (i < n)
    {
        if (s.empty() || hist[s.top()] <= hist[i])
            s.push(i++);
         else
        {
            tp = s.top();
            s.pop();
            area_with_top = hist[tp] * (s.empty() ? i : i - s.top() - 1);
 
            if (max_area < area_with_top)
                max_area = area_with_top;
        }
    }
    while (s.empty() == false)
    {
        tp = s.top();
        s.pop();
        area_with_top = hist[tp] * (s.empty() ? i : i - s.top() - 1);
 
        if (max_area < area_with_top)
            max_area = area_with_top;
    }
    return max_area;
}

int main()
{
	ll n;
	while(1)
	{
		scanf("%lld",&n);
		if(n==0)
			return 0;
		ll i;
		ll a[n];
		for(i=0;i<n;i++)
			scanf("%lld",&a[i]);
		ll res=getMaxArea(a,n);
		printf("%lld\n",res);
	}
	return 0;
}