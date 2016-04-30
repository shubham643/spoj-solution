#include<bits/stdc++.h>
using namespace std;

struct node
{
	int left,right;
	bool flag;
};

node save[100000];

bool findflag(node a)
{
	if(a.left<a.right)
		return false;
	else if(a.right==0)
		return true;
	else
		return false;
}

node construct(char *s,int st,int en,int index,int *left,int *right)
{
	if(st==en)
	{
		if(s[st]=='('){
			*left=*left+1;
			*right=*right+1;
			save[index].left=*left;
			save[index].right=*right;
			if(save[index].left<0||save[index].right<0)
				save[index].flag=false;
			else
				save[index].flag=true;
	//		save[index].flag=findflag(save[index]);
		}
		else{
			*left=*left-1;
			*right=*right-1;
			save[index].left=*left;
			save[index].right=*right;
			if(save[index].left<0||save[index].right<0)
				save[index].flag=false;
			else
				save[index].flag=true;
	//		save[index].flag=findflag(save[index]);
		}
		return save[index];
	}
	else
	{
		int mid=(st+en)>>1;
		node l=construct(s,st,mid,2*index,left,right);
		node r=construct(s,mid+1,en,2*index+1,left,right);
		if(!l.flag||!r.flag)
			save[index].flag=false;
		else
			save[index].flag=true;
		save[index].left=l.right;
		save[index].right=r.right;
//		save[index].flag=findflag(save[index])&&save[2*index+1].flag;
		return save[index];
	}
}

node update(char *s,int val,int rl,int rr,int index)
{
	if(val==rl&&val==rr)
	{
		if(s[val]==')'){
			save[index].left-=2;
			save[index].right-=2;
			if(save[index].left<0||save[index].right<0){
				cout<<"here";
				save[index].flag=false;
			}
			else
				save[index].flag=true;
		}
		else{
			save[index].left+=2;
			save[index].right+=2;
			if(save[index].left<0||save[index].right<0){
		//		cout<<"fuck";
				save[index].flag=false;
			}
			else{
				cout<<"fuck";
				save[index].flag=true;
			}
		}
		return save[index];
	}
	else if(val<rl||val>rr){
		node temp;
		temp.left=temp.right=0;
		temp.flag=true;
		return temp;
	}
	else
	{
		int mid=(rl+rr)>>1;
		if(val<=mid)
			update(s,val,rl,mid,2*index);
		else
			update(s,val,mid+1,rr,2*index+1);
		save[index].left=save[2*index].right;
		save[index].right=save[2*index+1].right;
		if(!save[2*index].flag||!save[2*index+1].flag)
				save[index].flag=false;
			else{
				cout<<"fuck";
				save[index].flag=true;
			}
		return save[index];
	}
}

int main()
{
	int test;
	for(test=1;test<=10;test++){
	int n;
	scanf("%d",&n);
	char s[n+1];
	scanf("%s",s);
	printf("Test %d:\n",test);
	int left=0,right=0;
	construct(s,0,n-1,1,&left,&right);
	int q;
	scanf("%d",&q);
	while(q--)
	{
		int val;
		scanf("%d",&val);
		if(val==0)
		{
			if(save[1].flag&&save[1].right==0)
				printf("YES\n");
			else
				printf("NO\n");
		}
		else
		{
			val--;
			if(s[val]==')')
				s[val]='(';
			else
				s[val]=')';
			update(s,val,0,n-1,1);
		}
	}
	}
	return 0;
}
