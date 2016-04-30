#include<bits/stdc++.h>
using namespace std;

struct node
{
	int index;
	int vol,val,parent,child[3];
};

node a[32005];
int c;
node res[32005];
int weight,tempweight;

int including(int i,int j,int count)
{
	if(count==0){
		return res[j].vol*res[j].val;
	}
	else if(count==1)
	{
		int ans=res[j].vol*res[j].val;
		tempweight=res[j].vol;
		int vol=res[j].vol;
		int k,temp;
		for(k=0;k<=res[j].index;k++)
		{
			if(i-vol-a[res[j].child[k]].vol>=0)
			{
				temp=ans+(a[res[j].child[k]].vol)*(a[res[j].child[k]].val);
				if(temp>ans){
					tempweight=vol+a[res[j].child[k]].vol;
					ans=temp;
				}
			}
		}
		return ans;
	}
	else if(count==2)
	{
		if(res[j].index<1)
			return -1;
		else if(res[j].index==1)
		{
			int vol=res[j].vol,ans;
			if(i-vol-a[res[j].child[0]].vol-a[res[j].child[1]].vol>=0)
			{	
				ans=res[j].vol*res[j].val+(a[res[j].child[0]].vol)*(a[res[j].child[0]].val)+(a[res[j].child[1]].vol)*(a[res[j].child[1]].val);
				tempweight=res[j].vol+a[res[j].child[0]].vol+a[res[j].child[1]].vol;
				return ans;
			}
			else{
				tempweight=99999999;
				return -1;
			}
		}
		else
		{
			int ans=-1;
			int temp=res[j].vol*res[j].val+(a[res[j].child[0]].vol)*(a[res[j].child[0]].val)+(a[res[j].child[1]].vol)*(a[res[j].child[1]].val)+(a[res[j].child[2]].vol)*(a[res[j].child[2]].val);
			int vol=res[j].vol+a[res[j].child[0]].vol+a[res[j].child[1]].vol+a[res[j].child[2]].vol;
			int k;
			for(k=0;k<3;k++)
			{
				if(i-vol+a[res[j].child[k]].vol>=0)
				{
					k=temp-(a[res[j].child[k]].vol)*(a[res[j].child[k]].val);
					if(k>ans){
						tempweight=res[j].vol+a[res[j].child[0]].vol+a[res[j].child[1]].vol+a[res[j].child[2]].vol-a[res[j].child[k]].vol;
						ans=k;
					}
				}
			}
			return ans;
		}
	}
	else
	{
		if(i>=res[j].vol+a[res[j].child[0]].vol+a[res[j].child[1]].vol+a[res[j].child[2]].vol)
		{
			int ans=res[j].vol*res[j].val+(a[res[j].child[0]].vol)*(a[res[j].child[0]].val)+(a[res[j].child[1]].vol)*(a[res[j].child[1]].val)+(a[res[j].child[2]].vol)*(a[res[j].child[2]].val);
			tempweight=res[j].vol+a[res[j].child[0]].vol+a[res[j].child[1]].vol+a[res[j].child[2]].vol;
			return ans;
		}
		else{
			tempweight=99999999;
			return -1;
		}
	}
}

int checkwithallattatchments(int i,int j)
{
	int maxm=-1,temp;
	temp=including(i,j,0);
	if(temp>maxm){
		weight=res[j].vol;
		maxm=temp;
	}
	temp=including(i,j,1);
	if(temp>maxm){
		weight=tempweight;
		maxm=temp;
	}
	temp=including(i,j,2);
	if(temp>maxm){
		weight=tempweight;
		maxm=temp;
	}
	temp=including(i,j,3);
	if(temp>maxm){
		weight=tempweight;
		maxm=temp;
	}
	return maxm;
}

int findit(int n,int k)
{
	int save[k+1][c+1];
	int i,j;
	for(i=0;i<=k;i++)
		save[i][0]=0;
	for(i=0;i<=c;i++)
		save[0][i]=0;
	for(i=1;i<=k;i++)
	{
		for(j=1;j<=c;j++)
		{
			int with=0,without=save[i][j-1];
			if(i>=res[j].vol)
			{
				int temp=checkwithallattatchments(i,j);
				if(temp!=-1){
					with=temp+save[i-weight][j-1];
					weight=-1;                   //add weight concept.
				}
			}
			save[i][j]=max(with,without);
		}
	}
	return save[k][c];
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		weight=-1;
		int n,k;
		c=0;
		scanf("%d%d",&k,&n);
		int i;
		for(i=1;i<=n;i++)
		{
			a[i].index=-1;
			scanf("%d%d%d",&a[i].vol,&a[i].val,&a[i].parent);
			if(a[i].parent)
			{
				(a[a[i].parent].index)++;
				a[a[i].parent].child[a[a[i].parent].index]=i;
			}
		}
		for(i=1;i<=n;i++)
		{
			if(!a[i].parent)
				res[++c]=a[i];
		}
		int ans=findit(n,k);
		printf("%d\n",ans);
	}
	return 0;
}