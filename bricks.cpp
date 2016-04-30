#include<bits/stdc++.h>
using namespace std;

char a[100005],b[100005];
bool mat[26][26];

int main()
{
	long long mod= pow(2,32);
	long long t;
	scanf("%lld",&t);
	while(t--)
	{
//		vector<long long> flag[26];
		scanf("%s%s",a,b);
		long long m;
		scanf("%lld",&m);
		long long i,j;
		for(i=0;i<26;i++)
			for(j=0;j<26;j++)
				mat[i][j]=false;
		char to[3];
		for(i=0;i<m;i++)
		{
			scanf("%s",to);
			mat[to[0]-'a'][to[1]-'a']=true;
			mat[to[1]-'a'][to[0]-'a']=true;
		}
		long long lena=strlen(a);
		long long lenb=strlen(b);
		if(lena!=lenb)
		{
			printf("-1\n");
			continue;
		}
/*		for(i=0;i<lena;i++)
		{
			flag[a[i]-'a'].push_back(i);
		}
*/		long long count=0;
		for(i=0;i<lena;i++)
		{
			if(a[i]!=b[i]&&mat[a[i]-'a'][b[i]-'a']==false)
				break;
			if(a[i]!=b[i])
			{
				bool check=false;
				for(j=i+1;j<lena;j++)
				{
					if(a[j]==b[i]){
						check=true;
						count=(count+2*(j-i)-1)%mod;
						break;
					}
					else if(!mat[a[j]-'a'][a[i]-'a']||!mat[b[i]-'a'][a[j]-'a'])
						break;
				}
				if(!check)
					break;
				a[j]=a[i];
				a[i]=b[i];
			}
		}
		if(i!=lena)
			printf("-1\n");
		else
			printf("%lld\n",count);
	}
	return 0;
}