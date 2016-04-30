#include<bits/stdc++.h>
using namespace std;

static bool checkit[100000000];

int main()
{
	int i;
	int save[500001];
	save[0]=0;
	checkit[0]=true;
	for(i=1;i<=500000;i++)
	{
		int temp=save[i-1]-i;
		if(checkit[temp]||temp<0)
			temp=save[i-1]+i;
		save[i]=temp;
		checkit[temp]=true;
	}
	while(1)
	{
		int n;
		scanf("%d",&n);
		if(n==-1)
			break;
		printf("%d\n",save[n]);
	}
	return 0;
}