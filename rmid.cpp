#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	vector<int> v;
	while(scanf("%d",&n))
	{
		if(n==-1){
			printf("%d\n",v.size()%2==0?v[v.size()/2-1]:v[v.size()/2]);
			int loc=v.size()%2==0?v.size()/2-1:v.size()/2;
			v.erase(v.begin()+loc);
		}
		else if(n==0){
			v.clear();
			cout<<endl;
		}
		else
			v.push_back(n);
	}
	return 0;
}