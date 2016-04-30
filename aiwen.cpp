#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pp;

int main()
{
	priority_queue<pp,vector<pp>,greater<pp> > pq;
	int n,k;
	cin>>n>>k;
	vector<int> v[n];
	for(int i=0;i<n;i++){
		for(int j=0;j<k;j++)
		{
			int val;
			cin>>val;
			v[i].push_back(val);
		}
	}
	for(int i=0;i<n;i++){
		pq.push(make_pair(v[i][0],i));
		v[i].erase(v[i].begin());
	}
	vector<int> res;
	for(int i=0;i<n*k;i++)
	{
		res.push_back(pq.top().first);
		pp temp=pq.top();
		pq.pop();
		int j=temp.second;
		if(!v[j].empty()){
			pq.push(make_pair(v[j][0],j));
			v[j].erase(v[j].begin());
		}
	}
	for(int i=0;i<n*k;i++)
		cout<<res[i]<<" ";
}