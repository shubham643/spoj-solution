#include<bits/stdc++.h>
using namespace std;

bool flag[10000000];
long saved[10000000];
long indexed;
bool seg[10000000];

void compute()
{
	long i,j;
	long b=sqrt(1000000000);
	for(i=2;i*i<=b;i++)
	{
		if(!flag[i])
		{
			saved[++indexed]=i;
			for(j=i*i;j<=b;j+=i)
				flag[j]=true;
		}
	}
	for(i;i<=b;i++)
		if(!flag[i])
			saved[++indexed]=i;
}

long binarysearch(long s,long e,long val)
{
	long mid=(s+e)/2;
	if(saved[mid]==val||s==e||e<s)
		return mid;
	else if(saved[mid]>val)
		return binarysearch(s,mid-1,val);
	else
		return binarysearch(mid+1,e,val);
}

void bysearch(long a,long b)
{
	long loc=binarysearch(0,indexed,a);
	long i;
	for(i=loc;i<=indexed&&saved[i]<=b;i++)
		printf("%ld\n",saved[i]);
}

void againcompute(long a,long b)
{
	long i,j,root=sqrt(1000000000);
	if(a<=root)
	{
		i=binarysearch(0,indexed,a);
		while(i<=indexed)
		{
			printf("%ld\n",saved[i]);
			i++;
		}
		a=root+1;
	}
	for(i=0;i<b-a+2;i++)
		seg[i]=false;
	for(i=0;i<=indexed;i++)
	{
		for(j=saved[i]-a%saved[i]+a;j<=b;j+=saved[i])
		{
			if(j-a==saved[i])
				seg[0]=true;
			seg[j-a]=true;
		}
	}
	for(i=0;i<=b-a;i++)
	{
		if(!seg[i])
			printf("%ld\n",i+a);
	}
}

int main()
{
	indexed=-1;
	long t;
	compute();
	scanf("%ld",&t);
	while(t--)
	{
		long root=sqrt(1000000000);
		long a,b;
		scanf("%ld%ld",&a,&b);
		if(b<=root)
			bysearch(a,b);
		else
		{
			againcompute(a,b);
		}
		printf("\n");
	}
	return 0;
}