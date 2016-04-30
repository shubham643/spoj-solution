#include<bits/stdc++.h>
using namespace std;

int flag[10000000];

void compute()
{
	long i,j;
	for(i=2;i*i<=1000000;i++)
	{
		if(!flag[i])
		{
			for(j=i*i;j<=1000000;j+=i){
				if(!flag[j])
					flag[j]=i;
			}
		}
	}
}

int main()
{
	compute();
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		int p[100],q[100],inp=-1,inq=-1;
		int tempa=a,tempb=b;
		while(flag[tempa]!=0)
		{
			p[++inp]=flag[tempa];
			tempa/=flag[tempa];
		}
		p[++inp]=tempa;
		while(flag[tempb]!=0)
		{
			q[++inq]=flag[tempb];
			tempb/=flag[tempb];
		}
		q[++inq]=tempb;
		int sizep=inp+1;
		int sizeq=inq+1;		
		int i,j;
		i=j=0;
		int prev=-1,index=-1;
		int res[100],inres=-1;
		while(i<sizep&&j<sizeq)
		{
			if(p[i]==q[j])
			{
				if(prev==p[i])
					res[inres]++;
				else
				{
					res[++inres]=1;
					prev=p[i];
				}
				i++; j++;
			}
			else if(p[i]>q[j])
				j++;
			else
				i++;
		}
		int ans=1;
		for(i=0;i<=inres;i++){
			ans*=(res[i]+1);
		}
		printf("%d\n",ans);
	}
	return 0;
}