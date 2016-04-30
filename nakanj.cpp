#include<bits/stdc++.h>
using namespace std;

int y_1,y_2;
int save[8][8];

struct node
{
	int s,e;
};

bool check(int a,int b)
{
	if(a==y_1&&b==y_2)
		return true;
	else
		return false; 
}

int findit(int x1,int x2)
{
	int i,j,res;
	queue<pair<int,node> > q;
	pair<int,node> temp;
	node n;
	temp.second.s=x1;
	temp.second.e=x2;
	temp.first=0;
	q.push(temp);
	while(1)
	{
		temp=q.front();
		q.pop();
		if(temp.second.s+2<8)
		{
			if(temp.second.e+1<8){
				if(check(temp.second.s+2,temp.second.e+1))
					{ res=temp.first+1; goto end; }
				if(save[temp.second.s+2][temp.second.e+1]!=-1)
					goto jump;
				n.s=temp.second.s+2;
				n.e=temp.second.e+1;
				save[temp.second.s+2][temp.second.e+1]=temp.first+1;
				q.push(pair<int,node>(temp.first+1,n));
			}
			if(temp.second.e-1>=0){
				if(check(temp.second.s+2,temp.second.e-1))
					{ res=temp.first+1; goto end; }
				if(save[temp.second.s+2][temp.second.e-1]!=-1)
					goto jump;
				save[temp.second.s+2][temp.second.e-1]=temp.first+1;
				n.s=temp.second.s+2;
				n.e=temp.second.e-1;
				q.push(pair<int,node>(temp.first+1,n));
			}
		}
		if(temp.second.s-2>=0)
		{
			if(temp.second.e+1<8){
				if(check(temp.second.s-2,temp.second.e+1))
					{ res=temp.first+1; goto end; }
				if(save[temp.second.s-2][temp.second.e+1]!=-1)
					goto jump;
				save[temp.second.s-2][temp.second.e+1]=temp.first+1;
				n.s=temp.second.s-2;
				n.e=temp.second.e+1;
				q.push(pair<int,node>(temp.first+1,n));
			}
			if(temp.second.e-1>=0){
				if(check(temp.second.s-2,temp.second.e-1))
					{ res=temp.first+1; goto end; }
				if(save[temp.second.s-2][temp.second.e-1]!=-1)
					goto jump;
				save[temp.second.s-2][temp.second.e-1]=temp.first+1;
				n.s=temp.second.s-2;
				n.e=temp.second.e-1;
				q.push(pair<int,node>(temp.first+1,n));
			}
		}
		if(temp.second.e+2<8)
		{
			if(temp.second.s+1<8){
				if(check(temp.second.s+1,temp.second.e+2))
					{ res=temp.first+1; goto end; }
				if(save[temp.second.e+2][temp.second.s+1]!=-1)
					goto jump;
				save[temp.second.e+2][temp.second.s+1]=temp.first+1;
				n.s=temp.second.s+1;
				n.e=temp.second.e+2;
				q.push(pair<int,node>(temp.first+1,n));
			}
			if(temp.second.s-1>=0){
				if(check(temp.second.s-1,temp.second.e+2))
					{ res=temp.first+1; goto end; }
				if(save[temp.second.s-1][temp.second.e+2]!=-1)
					goto jump;
				save[temp.second.s-1][temp.second.e+2]=temp.first+1;
				n.s=temp.second.s-1;
				n.e=temp.second.e+2;
				q.push(pair<int,node>(temp.first+1,n));
			}
		}
		if(temp.second.e-2>=0)
		{
			if(temp.second.s+1<8){
				if(check(temp.second.s+1,temp.second.e-2))
					{ res=temp.first+1; goto end; }
				if(save[temp.second.s+1][temp.second.e-2]!=-1)
					goto jump;
				save[temp.second.s+1][temp.second.e-2]=temp.first+1;
				n.s=temp.second.s+1;
				n.e=temp.second.e-2;
				q.push(pair<int,node>(temp.first+1,n));
			}
			if(temp.second.s-1>=0){
				if(check(temp.second.s-1,temp.second.e-2))
					{ res=temp.first+1; goto end; }
				if(save[temp.second.s-1][temp.second.e-2]!=-1)
					goto jump;
				save[temp.second.s-1][temp.second.e-2]=temp.first+1;
				n.s=temp.second.s-1;
				n.e=temp.second.e-2;
				q.push(pair<int,node>(temp.first+1,n));
			}
		}
		jump: ;
	}
	end:
	return res;

}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		char a[3],b[3];
		scanf("%s%s",a,b);
		int x1,x2;
		x1=a[0]-'a'+1;
		x2=a[1]-'0';
		y_1=b[0]-'a'+1;
		y_2=b[1]-'0';
		int i;
		for(i=0;i<8;i++)
			for(int j=0;j<8;j++)
				save[i][j]=-1;
		x1--; x2--; y_1--; y_2--;
		save[x1][x2]=0;
		int res=findit(x1,x2);
		printf("%d\n",res);
	}
	return 0;
}