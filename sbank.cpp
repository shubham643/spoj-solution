#include<bits/stdc++.h>
using namespace std;

int main()
{
	//int t;
	//scanf("%d",&t);
	//while(t--)
	{
		int n;
		scanf("%d",&n);
		set<string> m;
		map<string,int> mymap;
		map<string,int>::iterator kk;
		int i;
		for(i=0;i<n;i++)
		{
			string s;
			cin>>s;
	//		cout<<s;
			m.insert(s);
			kk=mymap.find(s);
			if(kk==mymap.end()){
				pair<string,int> pr(s,1);
				mymap.insert(pr);
			}
			else
			{
				int temp=kk->second;
				mymap.erase(kk);
				pair<string,int> pr(s,temp+1);
				mymap.insert(pr);
			}
		}
		set<string>::iterator ii;
		for(ii=m.begin();ii!=m.end();ii++)
		{
			cout<<*ii<<" "<<mymap[*ii]<<endl;
		}
	}
	return 0;
}