#include<bits/stdc++.h>
using namespace std;

map<int,int> store1,store2;
int flag[1000000];
void compute()
{
	int i,j;
	int b=sqrt(1000000000);
	for(i=2;i*i<=b;i++)
	{
		if(flag[i]==0)
		{
			flag[i]=i;
			for(j=i*i;j<=b;j+=i)
			{
				if(flag[j]==0)
					flag[j]=i;
			}
		}
	}
	for(i=i+1;i<=b;i++)
	{
		if(!flag[i])
			flag[i]=i;
	}
}

void storethem(int val,int power,int decide)
{
	if(decide==0){
	map<int,int>::iterator ii;
	while(val!=1)
	{
		ii=store1.find(flag[val]);
		if(ii==store1.end())
		{
			store1[flag[val]]=power;
		}
		else
		{
			ii->second+=power;
		}
		val=val/flag[val];
	}
	}
	else
	{
			map<int,int>::iterator ii;
	while(val!=1)
	{
		ii=store2.find(flag[val]);
		if(ii==store2.end())
		{
			store2[flag[val]]=power;
		}
		else
		{
			ii->second+=power;
		}
		val=val/flag[val];
	}
	}	
}

int main()
{
	compute();
	int t,p,q,r,s;
	scanf("%d",&t);
	while(t--)
	{
		store1.clear();
		store2.clear();
		int decide=0;
		scanf("%d%d%d%d",&p,&q,&r,&s); 
		storethem(p,q,decide);
		decide=1;
		storethem(r,s,decide);
		bool flag=false;
		int size1=store1.size();
		int size2=store2.size();
		int i,j;
		i=j=0;
		map<int,int>::iterator ii=store1.begin(),jj=store2.begin();
		while(jj!=store2.end()&&ii!=store1.end())
		{
			if(ii->first>jj->first)
			{
				ii++;
			}
			else if(ii->first<jj->first)
			{
				flag=true;
				break;
			}
			else if(ii->first==jj->first)
			{
				if(jj->second>ii->second)
				{
					flag=true;
					break;
				}
				ii++;
				jj++;
			}
		}
		if(jj!=store2.end()||flag)
			printf("not divisible\n");
		else 
			printf("divisible\n");
	}
	return 0;
}