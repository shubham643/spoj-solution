#include<bits/stdc++.h>
using namespace std;

int alen,blen;

void add(char a[1000],char b[1000])
{
	int index=-1,carry=0;
	char res[10000];
	int i=alen-1,j=blen-1;
	while(i>=0||j>=0)
	{
		++index;
		if(i>=0&&j>=0)
			res[index]=a[i]-'0'+b[j]+carry;
		else if(i>=0)
			res[index]=a[i]+carry;
		else
			res[index]=b[j]+carry;
		carry=0;
		if(res[index]>57)
		{
			carry=1;
			res[index]=res[index]-'9'-1+'0';
		}
		i--;
		j--;
	}
	if(carry)
		res[++index]='1';	
	res[++index]='\0';
	for(i=index-1;i>=0;i--)
		cout<<res[i];
}

void sub(char a[1000],char b[1000])
{
	int index=-1,carry=0;
	char res[10000];
	int i=alen-1,j=blen-1;
	while(i>=0)
	{
		++index;
		if(i>=0&&j>=0)
			res[index]=a[i]+'0'-b[j]-carry;
		else
			res[index]=a[i]-carry;
		
		if(res[index]<'0')
		{
			if(i>=0&&j>=0)
				res[index]=a[i]+10+'0'-b[j]-carry;
			else
				res[index]=a[i]+10-carry;
			carry=1;
		}
		else
			carry=0;
		
		i--;
		j--;
	}
	res[++index]='\0';
	for(i=index-1;i>=0;i--)
		cout<<res[i];
}

void mul(char a[1000],char b[1000])
{
	int index=-1,carry=0,maxm=-1;
	char res[10000];
	int i,j=blen-1;
	for(i=0;i<=alen*blen+2;i++)
		res[i]='0';
	int temp;
	while(j>=0)
	{

		i=alen-1;
		while(i>=0)
		{
			++index;
			temp=(a[i]-'0')*(b[j]-'0')+carry;
			
			res[index]+=temp%10;
			carry=temp/10;
			if(res[index]>'9')
			{
				res[index]=res[index]-'9'-1;
				carry++;
			}
			i--;
		}
		while(carry)
		{
			res[++index]+=carry%10;
			carry/=10;
		}
		if(index>maxm)
			maxm=index;
		index=j-blen+1;
		j--;
	}
	res[++maxm]='\0';
	for(i=maxm-1;i>=0;i--)
		cout<<res[i];
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		char s[10000];
		scanf("%s",s);
		int i;
		int len=strlen(s);
		i=0;
		char a[1000],b[1000],save;
		while(s[i]!='+'&&s[i]!='-'&&s[i]!='*')
		{
			a[i]=s[i];
			i++;
		}
		a[i]='\0';
		save=s[i];
		alen=i;
		i++;
		while(i<len)
		{
			b[i-alen-1]=s[i];
			i++;
		}
		b[i-alen-1]='\0';
		blen=len-alen-1;
		switch(save)
		{
			case '+': add(a,b);
					break;
			case '-': sub(a,b);
					break;
			case '*': mul(a,b);
		}
		printf("\n");
	}
	return 0;
}