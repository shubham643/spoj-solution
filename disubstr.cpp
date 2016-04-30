#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		char ch[1005];
		scanf("%s",ch);
		int count=0,l;
		set<string> myset;
		set<string>::iterator ii;
		string s=string(ch);
		int len=s.length();
		for(l=0;l<len;l++)
		{
			int i;
			for(i=l;i<len;i++)
			{
				string str=s.substr(l,i-l+1);
				ii=myset.find(str);
				if(ii==myset.end())
				{
					count++;
					myset.insert(str);
				}
			}
		}
		printf("%d\n",count);
	}
	return 0;
}
