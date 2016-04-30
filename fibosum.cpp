#include<bits/stdc++.h>
#define MOD 1000000007
using namespace std;

long long fib[2][2];
long long ans[2][2];

void mul()
{
	long long zz=((ans[0][0]*fib[0][0])%MOD+(ans[0][1]*fib[1][0])%MOD)%MOD;
	long long zo=((ans[0][0]*fib[0][1])%MOD+(ans[0][1]*fib[1][1])%MOD)%MOD;
	long long oz=((ans[1][0]*fib[0][0])%MOD+(ans[1][1]*fib[1][0])%MOD)%MOD;
	long long oo=((ans[1][0]*fib[0][1])%MOD+(ans[1][1]*fib[1][1])%MOD)%MOD;
	ans[0][0]=zz;
	ans[0][1]=zo;
	ans[1][0]=oz;
	ans[1][1]=oo;
}

void multiply()
{
	long long zz=((fib[0][0]*fib[0][0])%MOD+(fib[0][1]*fib[1][0])%MOD)%MOD;
	long long zo=((fib[0][0]*fib[0][1])%MOD+(fib[0][1]*fib[1][1])%MOD)%MOD;
	long long oz=((fib[1][0]*fib[0][0])%MOD+(fib[1][1]*fib[1][0])%MOD)%MOD;
	long long oo=((fib[1][0]*fib[0][1])%MOD+(fib[1][1]*fib[1][1])%MOD)%MOD;
	fib[0][0]=zz;
	fib[0][1]=zo;
	fib[1][0]=oz;
	fib[1][1]=oo;	
}

long long power(long long val)
{
	ans[0][0]=1;
	ans[0][1]=0;
	ans[1][0]=0;
	ans[1][1]=1;
	while(val)
	{
		if(val&1)
			mul();
		val>>=1;
		multiply();
	}
	return ans[0][0];
}

int main()
{
	long long t;
	scanf("%lld",&t);
	while(t--)
	{
		long long n,m;
		scanf("%lld%lld",&n,&m);
	//	n++;
		m++;

		fib[0][0]=1;
		fib[0][1]=1;
		fib[1][0]=1;
		fib[1][1]=0;
		long long a=power(n);
	//	cout<<a<<" ";

		fib[0][0]=1;
		fib[0][1]=1;
		fib[1][0]=1;
		fib[1][1]=0;
		long long b=power(m);
	//	cout<<b<<" ";
		if(b-a<0)
			printf("%lld\n",(b+MOD-a));
		else
			printf("%lld\n",b-a);
	}
	return 0;
}