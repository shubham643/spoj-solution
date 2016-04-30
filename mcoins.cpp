#include<bits/stdc++.h>
using namespace std;

bool a[1000001];

int main()
{
	int k,l,m;
	scanf("%d%d%d",&k,&l,&m);
	int b[m],maxm=0,i;
	for(i=0;i<m;i++)
	{
		scanf("%d",&b[i]);
		if(b[i]>maxm)
			maxm=b[i];
	}
	a[1]=true;
	for(i=2;i<=maxm;i++)
	{
		if(!a[i-1])
			a[i]=true;
		else if(i>=k&&!a[i-k])
			a[i]=true;
		else if(i>=l&&!a[i-l])
			a[i]=true;
	}
	for(i=0;i<m;i++)
		if(a[b[i]])
			putchar('A');
		else
			putchar('B');
	printf("\n");
	return 0;
}