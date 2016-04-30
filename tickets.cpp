#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		string s;
		cin>>s;
		int i,len;
		char a=s[0];
		len=s.length();
		if(s.length()<2){
			printf("NO\n");
			continue;
		}
		char b=s[1];
		if(a==b)
		{
			printf("NO\n");
			continue;
		}
		i=2;
		if(s.length()%2==1)
		{
			if(s[s.length()-1]!=s[0]){
				printf("NO\n");
				continue;
			}
			else
			{
				len--;
			//	cout<<"HER";
			}
		}
		while(i<len)
		{
			if(s[i]!=a||s[i+1]!=b)
			{
				break;
			}
			i+=2;
		}
		if(i<len)
		{
			printf("NO\n");
		}
		else
			printf("YES\n");
	}
	return 0;
}