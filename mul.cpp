#include<bits/stdc++.h>
using namespace std;

static char res[100000000];

void mul(char *s,char *l)
{
	int len1=strlen(s),len2=strlen(l),i,j;
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

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		char a[10001],b[10001];
		scanf("%s%s",a,b);
//		int lena=a.length();
//		int lenb=b.length();
		int lena=strlen(a);
		int lenb=strlen(b);
		int i;
		for(i=0;i<lena+lenb+1;i++)
			res[i]='0';
		mul(a,b);
		int len=strlen(res);
	//	cout<<res[0];
		i=len-1;
		while(i>=0&&res[i]=='0')
			i--;
		if(i<0)
			printf("0");
		for(i;i>=0;i--)
			printf("%c",res[i]);
		printf("\n");
	}
	return 0;
}