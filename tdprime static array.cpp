#include<bits/stdc++.h>
using namespace std;

static bool flag[100000000];
int counting;

void compute()
{
	int i,j;
	int b=10000;
	for(i=2;i<=b;i++)
	{
		if(!flag[i])
		{
			if(counting%100==1)
				printf("%d\n",i);
			counting++;
	//		saved[++indexed]=i;
			for(j=i*i;j<100000000;j+=i)
				flag[j]=true;
		}
	}
	for(i;i<100000000;i++)
	{
		if(!flag[i]){
			if(counting%100==1)
				printf("%d\n",i);
			counting++;
		}
	}
}

/*void findit(int a,int b)
{
	int i,j;
	for(i=0;i<=indexed;i++)
	{
		j=saved[i]-a%saved[i];
		if(j==saved[i])
			flag[0]=true;
		for(j;j<10000000;j+=saved[i])
			flag[j]=true;
	}
	for(i=0;i<b-a;i++)
	{
		if(!flag[i]){
			if(counting%100==1)
				printf("%d\n",a+i);
			counting++;
		}
	}
}
*/
int main()
{
	counting=1;
//	indexed=-1;
	compute();
	int i;
/*	for(i=1;i<=9;i++)
	{
		int j;
		for(j=0;j<10000000;j++)
			flag[j]=false;
		findit(i*10000000,(i+1)*10000000);
	}
*/	return 0;
}