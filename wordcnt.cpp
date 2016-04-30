#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	scanf("%d",&t);
	string s,word;
	getline(cin,s);
	while(t--)
	{
		getline(cin,s);
		int save=0,temp=0,prev=0;
		istringstream iss(s,istringstream::in);
		while(iss>>word)
		{
			int len=word.length();
			if(len==prev)
				temp++;
			else
			{
				prev=len;
				temp=1;
			}
			if(temp>save)
				save=temp;
		}
		printf("%d\n",save);
	}
	return 0;
}