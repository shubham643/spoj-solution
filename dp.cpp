#include<bits/stdc++.h>
using namespace std;

struct node
{
	int val,i,j;
};

class comp
{
public:
	bool operator()(const node &a,const node &b)
	{
		return a.val<b.val;
	}
};

int abs(char a,char b)
{
	int p=a-'0';
	int q=b-'0';
	p-=q;
	return p>0?p:q;
}

int finddis(int a,int b,int c,int d,string *s)
{
	if(s[c][d]==s[a][b])
	{
		if(s[c][d]=='X')
			return 2;
		else
			return 1;
	}
	else if(s[c][d]=='X'||s[a][b]=='X')
		return 2;
	else if(abs(s[c][d],s[a][b])==0)
		return 1;
	else if(abs(s[c][d],s[a][b])==1)
		return 3;
	else
		return 0;
}

void dijktra(int building,int *dis,string *s,int m,int n,int savei,int savej)
{
	cout<<"lode";
	set<node,comp> myset;
	set<node,comp>::iterator ii;
	int count=0;
	int save[m][n];
	bool flag[m][n];
	int i,j;
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			save[i][j]=9999999;
			flag[i][j]=false;
		}
	}
	node temp;
	temp.val=0;
	temp.i=savei;
	temp.j=savej;
	myset.insert(temp);
	ii=myset.begin();
//	cout<<ii->i<<" "<<ii->j<<" "<<ii->val<<"katgya";
	while(!myset.empty())
	{
		ii=myset.begin();
		if(flag[ii->i][ii->j])
		{
			myset.erase(ii);
			continue;
		}
		if(s[ii->i][ii->j]=='$'){
			dis[count]=ii->val;
			count++;
		}
		if(building==count)
			break;
		save[ii->i][ii->j]=ii->val;
		flag[ii->i][ii->j]=true;
		if(ii->i+1<m&&!flag[ii->i+1][ii->j]&&finddis(ii->i,ii->j,ii->i+1,ii->j,s))
		{
			temp.val=ii->val+finddis(ii->i,ii->j,ii->i+1,ii->j,s);
			temp.i=ii->i+1;
			temp.j=ii->j;
			myset.insert(temp);
		}
		if(ii->i-1>=0&&!flag[ii->i-1][ii->j]&&finddis(ii->i,ii->j,ii->i-1,ii->j,s))
		{
			temp.val=ii->val+finddis(ii->i,ii->j,ii->i-1,ii->j,s);
			temp.i=ii->i-1;
			temp.j=ii->j;
			myset.insert(temp);
		}
		if(ii->j-1>=0&&!flag[ii->i][ii->j-1]&&finddis(ii->i,ii->j,ii->i,ii->j-1,s))
		{
			temp.val=ii->val+finddis(ii->i,ii->j,ii->i,ii->j-1,s);
			temp.i=ii->i;
			temp.j=ii->j-1;
			myset.insert(temp);
		}
		if(ii->j+1<n&&!flag[ii->i][ii->j+1]&&finddis(ii->i,ii->j,ii->i,ii->j+1,s))
		{
			temp.val=ii->val+finddis(ii->i,ii->j,ii->i,ii->j+1,s);
			temp.i=ii->i;
			temp.j=ii->j+1;
			myset.insert(temp);
		}
		myset.erase(ii);
	}

}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int m,n;
		scanf("%d%d",&m,&n);
		string s[m];
		int i,j,savei,savej,building=0;
		bool flag=false;
		for(i=0;i<m;i++)
		{
			cin>>s[i];
			for(j=0;j<n;j++)
			{
				if(s[i][j]=='X')
				{
					savei=i;
					savej=j;
				}
				else if(s[i][j]=='$')
					building++;
			}
		}
		int dis[building],sum=0;
		dijktra(building,dis,s,m,n,savei,savej);
		for(i=0;i<building;i++)
			sum+=dis[i];
		int total=pow(2,building),res=9999999;
		for(i=0;i<total;i++)
		{
			int j=building;
			int sumwith=0,maxwith=-1,maxwithout=-1;
			while(j--)
			{
				if(i%10){
					if(dis[j]>maxwith)
						maxwith=dis[j];
					sumwith+=dis[j];
				}
				else
				{
					if(dis[j]>maxwithout)
						maxwithout=dis[j];
				}
				i=i>>1;
			}
			sumwith-=maxwith;
			int sumwithout=sum-maxwithout;
			if(max(sumwith,sumwithout)<res)
				res=max(sumwith,sumwithout);
		}
		printf("result is%d\n",res);
			cout<<"dono";
	}
	return 0;
}