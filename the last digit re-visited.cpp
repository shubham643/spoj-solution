#include<bits/stdc++.h>
using namespace std;
int main()
{int t;cin>>t;while(t--){int a[11][7];a[0][0]=1;a[0][1]=0;a[1][0]=1;a[1][1]=1;a[2][0]=4;a[2][1]=2;a[2][2]=4;a[2][3]=8;a[2][4]=6;a[3][0]=4;a[3][1]=3;a[3][2]=9;a[3][3]=7;a[3][4]=1;a[4][0]=2;a[4][1]=4;a[4][2]=6;a[5][0]=1;a[5][1]=5;a[6][0]=1;a[6][1]=6;a[7][0]=4;a[7][1]=7;a[7][2]=9;a[7][3]=3;a[7][4]=1;a[8][0]=4;a[8][1]=8;a[8][2]=4;a[8][3]=2;a[8][4]=6;a[9][0]=2;a[9][1]=9;a[9][2]=1;string p;cin>>p;int b=p[p.length()-1]-'0';long long q;cin>>q;if(q==0){printf("1\n");continue;}long long temp=q%(a[b][0]);if(temp==1)printf("%d\n",b);else if(temp==0){printf("%d\n",a[b][a[b][0]]);}else{printf("%d\n",a[b][temp]);}}return 0;}


/*#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;scanf("%d",&t);
    while(t--)
    {
    long long a,b,res;
    scanf("%lld%lld",&a,&b);
    if(b==0)
    {
        printf("1\n");
        continue;
    }
    long long c=1,fix=a%10,d=fix*fix;
    d%=10;
    while(d!=fix){
        d*=fix;
        d%=10;
        c++;
    }
    b%=10; b%=c;
    if(!b)
        b=c;
    res=pow(a,b);
    printf("%lld\n",res%10);
    }
}*/