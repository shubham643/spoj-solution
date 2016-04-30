#include<bits/stdc++.h>
#define S 100000
using namespace std;
int k,a[3*S];
int c;
int leftmost;
void update(int idx,int l,int r,int val)
{
	int two=idx<<1;
	if(l==r)
	{
		if(c==0)
			leftmost=idx;
		if(!a[idx])
			c++;
		a[idx]+=val;
		return;
	}
	if(a[idx<<1]<=k-val){
		update(two,l,(l+r)>>1,val);
		a[idx]=min(a[two],a[two+1]);
	}
	else{
		update(two+1,(l+r)>>1 +1,r,val);
		a[idx]=min(a[two],a[two+1]);
	}
}

int main()
{
	int test;
	scanf("%d",&test);
	while(test--)
	{
		c=0;
		int n,val,i;
		scanf("%d%d",&k,&n);
		for(i=0;i<3*S;i++)
			a[i]=0;
		int cnt=0;
		char s[1024];
		while(n)
		{
			scanf("%d",&val);
			gets(s);
			if(s[0]=='b')
			{
				sscanf(&s[2],"%d %d",&cnt,&val);
				n-=cnt;
				while(cnt--)
				{
					update(1,1,S,val);
				}	
			}
			else
			{
				sscanf(s,"%d",&val);
				n--;
				update(1,1,S,val);
			}
		}
		int sum=0;
		for(i=leftmost;i<=leftmost+c-1;i++){
			cout<<a[i]<<" ";
			sum+=k-a[i];
		}
		printf("%d %d\n",c,sum);
	}
	return 0;
}