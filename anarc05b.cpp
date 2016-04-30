#include<bits/stdc++.h>
using namespace std;
typedef pair<long long,long long> pp;

int main()
{
	long long l1;
	while(1)
	{
		scanf("%lld",&l1);
		if(l1==0)
			return 0;
		long long a[l1],s1[l1];
		long long i;
		cin>>a[0];
		s1[0]=a[0];
		for(i=1;i<l1;i++){
			scanf("%lld",&a[i]);
			s1[i]=s1[i-1]+a[i];
		}
		long long l2;
		scanf("%lld",&l2);
		long long b[l2],s2[l2];
		cin>>b[0];
		s2[0]=b[0];
		for(i=1;i<l2;i++){
			scanf("%lld",&b[i]);
			s2[i]=s2[i-1]+b[i];
		}
		long long j=0;
		i=0;
		list<pp> lst;
		while(i<l1&&j<l2)
		{
			if(a[i]==b[j])
			{
				lst.push_back(pp(i,j));
				i++;
				j++;
			}
			else if(a[i]>b[j])
				j++;
			else
				i++;
		}
		long long res=0;
		pp last(-1,-1);
		while(!lst.empty())
		{
			pp temp=lst.front();
			if(last.first==-1)
			{
				if(s1[temp.first]>s2[temp.second])
					res+=s1[temp.first];
				else
					res+=s2[temp.second];
				last=pp(temp.first,temp.second);
			}
			else
			{
				long long val1=s1[last.first];
				long long val2=s2[last.second];
				if(s1[temp.first]-val1>s2[temp.second]-val2)
					res+=s1[temp.first]-val1;
				else
					res+=s2[temp.second]-val2;
				last=pp(temp.first,temp.second);
			}
			lst.pop_front();
		}
		long long val1=last.first==-1?0:s1[last.first];
		long long val2=last.second==-1?0:s2[last.second];
		if(s1[l1-1]-val1>s2[l2-1]-val2)
					res+=s1[l1-1]-val1;
				else
					res+=s2[l2-1]-val2;
		printf("%lld\n",res);
	}
	return 0;
}