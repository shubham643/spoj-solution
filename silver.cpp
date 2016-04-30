#include<bits/stdc++.h>
using namespace std;

int main()
{
	while(1)
	{
		int n;
		scanf("%d",&n);
		if(n==0)
			break;
		int res=0;
		while(n>1)
		{
			n>>=1;
			res++;
		}
		printf("%d\n",res);
	}
	return 0;
}