/*input
25114
1111111111
3333333333
*/


#include<iostream>
#include<stdio.h>
#include<string.h>
#include<math.h>
#define ll long long
using namespace std;

ll finding(char *s,int len)
{
	ll last,lastlast;
	lastlast=1;
	if(len==1)
		return 1;
	if(s[1]!='0')
		last=1;
	else
		last=0;
	ll temp=(s[0]-'0')*10+s[1]-'0';
	if(temp<=26)
		last++;
	ll i;
	for(i=2;i<len;i++)
	{
		if(s[i]!='0')
			temp=last;
		else
			temp=0;
		int num=(s[i-1]-'0')*10+s[i]-'0';
		if(num<=26&&s[i-1]!='0')
			temp+=lastlast;
		lastlast=last;
		last=temp;
	}
	return last;
}

int main()
{
	char s[10001];
	while(1)
	{
	    ll i;
		scanf("%s",s);
		if(s[0]=='0')
			return 0;
		int len=strlen(s);
		uint64_t res1=finding(s,len);
		cout<<res1<<endl;
	}
	return 0;
}
