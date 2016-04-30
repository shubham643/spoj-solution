#include<bits/stdc++.h>
using namespace std;

string divide(string s,int num)
{
	string res="";
	int len=s.length();
	int i,carry=0,rem;
	i=0;
	if(s[0]=='1')
	{
		carry=1;
		i=1;
	}
	for(i;i<len;i++)
	{
		if((s[i]-'0')%2==1)
			rem=1;
		else
			rem=0;
		res+=(carry*10+s[i]-'0')/2+'0';
		carry=rem;
	}
	return res;
}

void mul(string s,string l,char *res)
{
	int len1=s.length(),len2=l.length(),i,j;
	int carry=0,index=-1,maxin=-1;
//	cout<<"len1"<<len1<<" "<<"len2"<<len2<<endl;
	for(i=len1-1;i>=0;i--)
	{
		index=len1-i-2;
		for(j=len2-1;j>=0;j--)
		{
			int val=carry+(s[i]-'0')*(l[j]-'0');
			res[++index]+=val%10;
			carry=val/10;
			if(res[index]>'9')
			{
				res[index]=res[index]-'9'-1+'0';
				carry++;
			}
		}
		while(carry)
		{
			res[++index]+=carry%10;
			carry/=10;
		}
		if(index>maxin)
			maxin=index;
	}
	res[++maxin]='\0';
}

void compute(string small,string large,char *res)
{
	string temp;
	int lens=small.length(),lenl=large.length();
	int i,j;
	i=lens-1;
	while(i>=0&&small[i]=='9')
	{
		small[i]='0';
		i--;
	}
	if(i<0)
	{
		string temp="1";
		temp+=small;
		small=temp;
		lens++;
	}
	else
		small[i]+=1;
	small=divide(small,2);
	mul(small,large,res);
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		string s1,s2;
		char res[100],res1[100];
		int i;
		for(i=0;i<70;i++)
			res[i]=res1[i]='0';
		cin>>s1;
		cin>>s2;

		compute(s1,s2,res);
		compute(s2,s1,res1);
		int len1=strlen(res);
		int len2=strlen(res1);
		
		if(len1>len2)
		{
			for(i=len1-1;i>=0;i--)
				cout<<res[i];
		}
		else if(len2>len1)
		{
			for(i=len2-1;i>=0;i--)
				cout<<res1[i];
		}
		else
		{
			i=len1-1;
			while(i>=0&&res1[i]==res[i])
				i--;
			if(i<len1&&res[i]>res1[i])
			{
				for(i=len1-1;i>=0;i--)
					cout<<res[i];		
			}
			else
			{
				for(i=len2-1;i>=0;i--)
					cout<<res1[i];		
			}
		}
		cout<<endl;
	}	
	return 0;
}