#include<bits/stdc++.h>
using namespace std;
#define kth(i,k) (((i) >> (k)) & 1)
#define ison(x, i) (((x) >> (i)) & 1)
const int MAX=20;
long long dp[1 << MAX];

int main()
{
	long long t;
	scanf("%lld",&t);
	while(t--)
	{
		long long n;
		scanf("%lld",&n);
		long long a[20][20];
		long long i,j,k;
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
				scanf("%lld",&a[i][j]);
		dp[0]=1;
		for(i=1;i< (1<<n) ;i++)
		{
			j=0;
			dp[i]=0;
			for(k=0;k<n;k++)
				j+=ison(i,k);
			for(k=0;k<n;k++)
			{
				if(a[j-1][k]&&ison(i,k))
					dp[i]+=dp[i & ~(1 << k)];
			}
		}
		printf("%lld\n",dp[(1<<n)-1]);
	}
	return 0;
}

/*
long long main(){
	long long n,T;
  ios::sync_with_stdio(0);
  cin >> T;
  while(T--){
  	long long a[20][20];
    cin >> n;
    for(long long i = 0; i < n; i++){
      for(long long j = 0; j < n; j++){
         cin >> a[i][j];
      }
    }
    long long i, j, k;
    dp[0] = 1;
    for(i = 1; i < (1 << n); i++){
      j = 0;
      dp[i] = 0;
      for(k = 0; k < n; k++){
         j += ison(i, k); 
      }
      for(k = 0; k < n; k++){
         if(a[j - 1][k] && ison(i, k)){
            dp[i] += dp[i & ~(1 << k)];
         }
      }
    }
    cout << dp[(1 << n) - 1] << endl;
  }
  return 0;
}
*/