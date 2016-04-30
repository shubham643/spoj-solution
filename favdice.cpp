#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		double n,res;
		cin>>n;
		res=0;
		double temp=n;
		while(n>=1)
		{
			res+=double(temp/n);
			n--;
		}
		printf("%.2lf\n",res);
	}
	return 0;
}