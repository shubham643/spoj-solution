#include<bits/stdc++.h>
using namespace std;

struct node
{
	int index;
	float x,y;
};

node first;

int orientation(node a,node b,node c)
{
	float val=(b.y-a.y)*(c.x-b.x)-(b.x-a.x)*(c.y-b.y);
	if(val==0)
		return 0;
	return val<0?2:1;
}

float dis(node a,node b)
{
	return (b.y-a.y)*(b.y-a.y)+(b.x-a.x)*(b.x-a.x);
}

bool cmp(node a,node b)
{
	int o=orientation(first,a,b);
	if(o==0.0)
		return dis(first,a)<dis(first,b);
	return o==2?true:false;
}

node previous(list<node> stk)
{
	stk.pop_back();
	return stk.back();
}

int main()
{
	int test;
	scanf("%d",&test);
	while(test--)
	{
		int n;
		scanf("%d",&n);
		node a[n];
		int i;
		for(i=0;i<n;i++)
		{
			scanf("%f%f",&a[i].x,&a[i].y);
			a[i].index=i+1;
		}
		node minm=a[0];
		int idx=0;
		for(i=1;i<n;i++)
		{
			if(a[i].y<minm.y)
			{
				idx=i;
				minm=a[i];
			}
			else if(a[i].y==minm.y&&a[i].x<minm.x)
			{
				idx=i;
				minm=a[i];
			}
		}
		if(n==1)
		{
			printf("0.00\n1\n\n");
			continue;
		}
		else if(n==2)
		{
			if(a[0].x==a[1].x&&a[1].y==a[0].y)
			{
				printf("0.00\n%d\n",idx+1);
			}
			else
			{
				float val=dis(a[0],a[1]);
				val=sqrt(val);
				val=2*val;
				printf("%.2f\n%d %d\n",val,idx+1,idx==0?2:1);
			}
			printf("\n");
			continue;
		}
		node temp=a[idx];
		a[idx]=a[0];
		a[0]=temp;
		first=a[0];
		sort(a,a+n,cmp);
		list<node> stk;
		stk.clear();
		stk.push_back(a[0]);
		stk.push_back(a[1]);
		stk.push_back(a[2]);
		if(n==3)
		{
			if(orientation(a[0],a[1],a[2])==0)
			{
				float val=dis(a[0],a[2]);
				val=sqrt(val);
				val=2*val;
				printf("%f\n%d %d\n\n",val,a[0].index,a[2].index);
			}
			continue;
		}
		float resultdis=0.00;
		for(i=3;i<n;i++)
		{
			while(stk.size()>1&&orientation(previous(stk),stk.back(),a[i])!=2)
				stk.pop_back();
			stk.push_back(a[i]);
		}
		int hai=stk.size();
		list<node> lst1;
		node last;
		int counting=0;
		node aakhri;
		while(!stk.empty())
		{
			if(counting==0)
			{
				last=stk.front();
				counting++;
				lst1.push_back(last);
				stk.pop_front();
				continue;
			}
			resultdis+=sqrt(dis(stk.front(),last));
			lst1.push_back(stk.front());
			last=stk.front();
			if(counting==hai-1)
				aakhri=stk.front();
			stk.pop_front();
			counting++;
		}
		resultdis+=sqrt(dis(aakhri,a[0]));
		printf("%.2f\n",resultdis);
		while(!lst1.empty())
		{
			printf("%d ",lst1.front().index);
			lst1.pop_front();
		}
		cout<<endl<<endl;
	}
	return 0;
}