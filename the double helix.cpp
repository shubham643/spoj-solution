#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
	ll l1,l2;
	while(1)
	{
		scanf("%lld",&l1);
		if(l1==0)
			break;
		ll a[l1];
		ll i;
		for(i=0;i<l1;i++)
			scanf("%lld",&a[i]);
		scanf("%lld",&l2);
		ll b[l2];
		for(i=0;i<l2;i++)
			scanf("%lld",&b[i]);
		ll j;
		i=j=0;
		ll s1,s2,res=0;
		s1=s2=0;
		while(i<l1&&j<l2)
		{
			if(a[i]==b[j])
			{
				s1+=a[i];
				s2+=b[j];
				res+=max(s1,s2);
				i++;
				j++;
				s1=s2=0;
			}
			else
			{
				if(a[i]<b[j])
				{
					s1+=a[i];
					i++;
				}
				else
				{
					s2+=b[j];
					j++;
				}

			}
		}
		while(i<l1)
			s1+=a[i++];
		while(j<l2)
			s2+=b[j++];
		res+=max(s1,s2);
		printf("%lld\n",res);
	}
	return 0;
}