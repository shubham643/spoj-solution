#include<iostream>
#include<stdio.h>
#include<math.h>
#include<bits/stdc++.h>
using namespace std;

double findslop(pair<int,int> a,pair<int,int> b)
{
	double temp;
	temp=(b.second-a.second)*1.0/(b.first-a.first);
	return temp;
}

int main()
{
	vector<pair<int,int> > v;
	int n,x,y;
	int count;
	scanf("%d",&n);
	while(n--)
	{
		scanf("%d%d",&x,&y);
		pair<int,int> p;
		p.first=x;
		p.second=y;
		v.push_back(p);
	}
	int i,j,k;
	for(i=0;i<v.size();i++)
	{
		for(j=i+1;j<v.size();j++)
		{
			for(k=j+1;k<v.size();k++)
			{
				double slop1,slop2;
				slop1=findslop(v[i],v[j]);
				slop2=findslop(v[j],v[k]);
				if(slop1!=slop2)
					count++;
			}
		}
	}
	printf("%d",count);
	return 0;
}