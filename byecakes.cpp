#include<bits/stdc++.h>
using namespace std;

int findit(int a,int b)
{
	if(b>=a)
		return 1;
	if(a%b==0)
		return a/b;
	return a/b+1;
}

int main()
{
	int a,b,c,d,e,f,g,h;
	while(1)
	{
		scanf("%d%d%d%d%d%d%d%d",&a,&b,&c,&d,&e,&f,&g,&h);
		if(a==-1)
			return 0;
		int maxm=0;
		int temp;
		temp=findit(a,e);
		if(temp>maxm)
			maxm=temp;
		temp=findit(b,f);
		if(temp>maxm)
			maxm=temp;
		temp=findit(c,g);
		if(temp>maxm)
			maxm=temp;
		temp=findit(d,h);
		if(temp>maxm)
			maxm=temp;
		if(a==b&&c==d&&d==0)
			printf("0 0 0 0\n");
		else
			printf("%d %d %d %d\n",maxm*e-a,maxm*f-b,maxm*g-c,maxm*h-d);
	}
	return 0;
}