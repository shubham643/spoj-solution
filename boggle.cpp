#include<bits/stdc++.h>
using namespace std;

int val(string s)
{
	int len=s.length();
	if(len<=4)
		return 1;
	if(len==5)
		return 2;
	if(len==6)
		return 3;
	if(len==7)
		return 5;
	else
		return 11;
}

int main()
{
	int n;
	scanf("%d",&n);
	int score[n+1];
	int i;
	for(i=0;i<=n;i++)
		score[i]=0;
	map<string,int> dec;
	set<string> st;
	cin.ignore();
	for(i=1;i<=n;i++)
	{
		string s,word;
		getline(cin,s);
		istringstream iss(s,istringstream::in);
		while(iss>>word)
		{
			int value=val(word);
			if(st.find(word)!=st.end())
			{
				if(dec.find(word)!=dec.end())
				{
					score[dec[word]]-=value;
					dec.erase(word);
				}
			}
			else
			{
				score[i]+=value;
				st.insert(word);
				dec[word]=i;
			}
		}
	}
	int res=0;
	for(i=1;i<=n;i++)
		if(score[i]>res)
			res=score[i];
	printf("%d",res);
	return 0;
}