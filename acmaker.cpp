#include<bits/stdc++.h>
using namespace std;

int finditutil(string save,string abbrev,int abblen,int i,int j)
{
	if(j==abblen)
		return 0;
	if(save[i]==abbrev[j]&&j==abblen-1)
		return 1;
	return (save[i]==save[j]?finditutil(save,abbrev,abblen,i+1,j+1):0 + finditutil(save,abbrev,abblen,i+1,j));
}

int findit(int count,int i,string save,string abbrev,int j,int abblen)
{
	return finditutil(save,abbrev,abblen-(count-1-i),0,abblen-j-(count-1-i));
}

int main()
{
	int n;
	while(1)
	{
		scanf("%d",&n);
		if(n==0)
			break;
		set<string> mp;
		int i;
		string s;
		for(i=0;i<n;i++)
		{
			cin>>s;
			mp.insert(s);
		}
		string temp;
		while(1)
		{
			string abbrev;
			string save[151];
			getline(cin,temp);
			if(temp=="LAST CASE")
				break;
			string word;
			int count=0,abblen;
			istringstream iss(temp);
			while(iss>>word)
			{
				if(mp.find(word)!=mp.end())
					continue;
				if(count==0){
					abbrev=word;
					continue;
				}
				save[count]=word;
				count++;
			}
			abblen=abbrev.length();
			for(i=0;i<abblen;i++)
				abbrev[i]=abbrev[i]-'A'+'a';
			int dp[count][abblen];
			for(i=0;i<count;i++)
				for(int j=0;j<abblen;j++)
					dp[i][j]=-1;
			int maxm=1+abblen-count;
			for(i=count-1;i>=0;i--)
			{
				for(j=count-i;j<=count-i+maxm-1;j++)
				{
					dp[i][j]=findit(save[i],abbrev,0,abblen-j,abblen-j+maxm-1)+(i<count-1?dp[i+1][])
				}
			}
			int ans=0;
			for(i=1;i<=1+abblen-count;i++)
				ans+=dp[0][i];
			printf("%d\n",ans);
		}
	}	
	return 0;
}