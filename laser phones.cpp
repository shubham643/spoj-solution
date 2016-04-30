#include<bits/stdc++.h>
#define INTMAX 999
using namespace std;

char mat[105][105];
int save1i,save1j,save2i,save2j;

int minm(int a,int b,int c,int d)
{
	return min(a,min(b,min(c,d)));
}

int findit(int i,int j,char last,int w,int h)
{
	if(i==save2i&&j==save2j)
		return 0;
	if(mat[i][j]=='*')
		return INTMAX;
	if(i<0||i>=w||j<0||j>=h)
		return INTMAX;
	int temp1=(last=='n'||last=='r')?findit(i,j+1,last,w,h):(1+findit(i,j+1,'r',w,h));
	int temp2=(last=='n'||last=='l')?findit(i,j-1,last,w,h):(1+findit(i,j-1,'l',w,h));
	int temp3=(last=='n'||last=='u')?findit(i+1,j,last,w,h):(1+findit(i+1,j,'u',w,h));
	int temp4=(last=='n'||last=='d')?findit(i-1,j,last,w,h):(1+findit(i-1,j,'d',w,h));
	return minm(temp1,temp2,temp3,temp4);
}

int main()
{
	int w,h;
	scanf("%d%d",&w,&h);
	int i,j;
	bool flag=false;
	for(i=0;i<w;i++)
	{
		scanf("%s",mat[i]);
		j=0;
		for(j=0;j<h;j++)
		{
			if(mat[i][j]=='C'&&!flag)
			{
				cout<<"here";
				save1i=i;
				save1j=j;
				flag=true;
			}
			else if(mat[i][j]=='C'&&flag)
			{
				save2i=i;
				save2j=j;
				break;
			}
		}
	}
	int res=findit(save1i,save1j,'n',w,h);
	printf("%d",res);
	return 0;
}