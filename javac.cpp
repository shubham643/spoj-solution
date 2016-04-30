#include<bits/stdc++.h>
using namespace std;

int main()
{
	string s;
	while(cin>>s)
	{
		int flag=0;
		string res="";
		int len=s.length(),i;
		if(s[0]<'a'||s[0]=='_')
		{
			cout<<"Error!"<<endl;
			continue;
		}
		else
		{
			char temp[2];
			temp[0]=s[0];
			temp[1]='\0';
			res+=temp;
			for(i=1;i<len;i++)
			{
				if(s[i]=='_')
				{
					if(i+1>=len||s[i+1]<'a'||flag==2){
						cout<<"Error!"<<endl;
						goto again;
					}
					else
					{
						flag=1;
						i++;
						char temp[2];
						temp[0]=s[i]+'A'-'a';
						temp[1]='\0';
						res+=temp;
					}
				}
				else if(s[i]<'a')
				{
					if(flag==1)
					{
						cout<<"Error!"<<endl;
						goto again;
					}
					res+="_";
					char temp[2];
					temp[0]=s[i]+'a'-'A';
					temp[1]='\0';
					res+=temp;
				}
				else
				{
					char temp[2];
					temp[0]=s[i];
					temp[1]='\0';
					res+=temp;
				}
			}
			cout<<res<<endl;
		}
		again: ;
	}
	return 0;
}