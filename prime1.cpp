#include<bits/stdc++.h>
using namespace std;

vector<int> v;
bool flag[100000];

void compute()
{
	int j;
	int b=sqrt(1000000000);
	for(j=3;j*j<=b;j+=2)
	{
		if(!flag[j])
		{
			int temp=j<<1;
			v.push_back(j);
			for(int i=temp+j;i<=b;i+=temp)
				flag[i]=true;
		}
	}
	for(j;j<=b;j+=2)
		if(!flag[j])
			v.push_back(j);
}

void again_compute(int a,int b)
{
	bool seg[b-a+2];
	for(int i=0;i<b-a+2;i++)
		seg[i]=false;
	for(int i=0;i<v.size();i++)
	{
		for(int j=v[i]-a%v[i]+a;j<=b;j+=v[i]){
			seg[j-a]=true;
		}
		if(a%v[i]==0)
			seg[0]=true;
	}
	int i;
	if(a&1)	i=0;
	else i=1;
	for(i;i<=b-a;i+=2)
		if(!seg[i])
			printf("%d\n",i+a);
}

int main()
{
	int root=sqrt(1000000000);
	int t;
	cin>>t;
	compute();
	while(t--)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		if(a<=2&&b>=2)
			printf("2 ");
		if(b<=root)
		{
			vector<int>::iterator ii;
			ii=lower_bound(v.begin(),v.end(),a);
			for(ii;ii!=v.end() && *ii<=b;ii++)
				printf("%d\n",*ii);
		}
		else if(a<=root){
			vector<int>::iterator ii;
			ii=lower_bound(v.begin(),v.end(),a);
			for(ii;ii!=v.end() && *ii<=b;ii++)
				printf("%d\n",*ii);	
			again_compute(root+1,b);
		}
		else
			again_compute(a,b);
		printf("\n");
	}
}