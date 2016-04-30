#include<bits/stdc++.h>
using namespace std;

char s[1000009];
string res;


void change(int len)
{
	int i,j;
	if(len%2==0)
	{
		i=len/2-1;
		j=len/2;
		while(i>=0&&s[i]=='9')
		{
			s[i]=s[j]='0';
			i--; j++;
		}
		if(i>=0)
		{
			s[i]++; s[j]++;
		}
		else
		{
			res="1";
			s[j-1]='1';
			res+=s;
		}
	}
	else
	{
		i=len/2;
		if(s[i]!='9')
			s[i]++;
		else
		{
			s[i]='0';
			j=i+1;
			i--;
			while(i>=0&&s[i]=='9')
			{
				s[i]=s[j]='0';
				i--; j++;
			}
			if(i>=0)
			{
				s[i]++; s[j]++;
			}
			else
			{
				res="1";
				s[j-1]='1';
				res+=s;
			}		
		}
	}
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		res="";
		scanf("%s",s);
		int i,j,len=strlen(s);
		i=0,j=len-1;
		int flag=0;
		while(i<j)
		{
			if(s[i]!=s[j])
			{
				if(s[i]>s[j]){
					flag=2;
					s[j]=s[i];
				}
				else
				{
					flag=1;
					s[j]=s[i];
				}
			}
			i++;
			j--;
		}
		if(flag!=2)
			change(len);
		if(res!="")
			cout<<res<<endl;
		else
			printf("%s\n",s);
	}
	return 0;
}