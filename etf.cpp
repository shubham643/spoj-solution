#include<bits/stdc++.h>
using namespace std;

long long a[1000001];

void sieve()
{
	long long b=1000;
	long long i,j;
	for(i=2;i<=b;i++)
	{
		if(a[i])
			continue;
		for(j=i+i;j<=1000000;j+=i)
			a[j]=i;
	}
}

long long findtemp(long long i,vector<long long> v,long long val)
{
	long long count=0,ans=1,c=0;
	while(i)
	{
		if(i&1)
		{
			ans*=v[c];
			count++;
		}
		i=i>>1;
		c++;
	}
	if(count&1)
		return -1*val/ans;
	else
		return val/ans;
}

int main()
{
	int t;
	scanf("%d",&t);
	sieve();
	while(t--)
	{
		long long n;
		scanf("%lld",&n);
		long long val=n;
		set<long long> factor;
		while(n!=1)
		{
			if(!a[n])
				factor.insert(n);
			else
				factor.insert(a[n]);
			if(!a[n])
				break;
			else
				n/=a[n];
		}
		long long size=factor.size();
		long long till=pow(2,size);
		till--;
		cout<<"till: "<<till<<endl;
		long long i,product=1;
		set<long long>::iterator ii;
		n=val;
		vector<long long> v;
		for(ii=factor.begin();ii!=factor.end();ii++)
		{
//			n=n-(val)/(*ii);
			v.push_back(*ii);
		}
		cout<<"n: "<<n<<endl;
		long long finres=val;
		cout<<"finres: "<<finres<<endl;
		for(i=1;i<=till;i++)
		{
			finres+=findtemp(i,v,val);
			cout<<finres<<endl;
		}
		printf("%lld\n",finres);
	}
	return 0;
}