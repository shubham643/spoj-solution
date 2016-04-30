#include<bits/stdc++.h>
using namespace std;

string s[100001];

int flag[26];

int findd(int i)
{
    while(flag[i]!=-1&&flag[i]!=i)
      i=flag[i];
    return i;
}

int unionn(int u,int v)
{
    while(flag[u]!=-1)
      u=flag[u];
    while(flag[v]!=-1)
      v=flag[v];
    flag[v]=u;
}

int finddtill(int a)
{
  if(flag[a]==-1)
    return -1;
  else
    return findd(a);
}

int main()
{
     int t;
     scanf("%d",&t);
     while(t--)
     {
          int n;
          scanf("%d",&n);
          int i;
          int start[26],ending[26];
              for(i=0;i<26;i++)
                  start[i]=ending[i]=0;
          for(i=0;i<26;i++)
              flag[i]=-1;
          for(i=0;i<n;i++)
          {
              cin>>s[i];
              int u=s[i][0]-'a';
              int v=s[i][s[i].length()-1]-'a';
              start[u]++;
              ending[v]++;
              int parx,pary;
              parx=findd(u);
              pary=findd(v);
              if(u==v&&flag[u]==-1)
                flag[u]=u;
         //     cout<<parx<<pary;
              else if(parx!=pary)
                  unionn(u,v);
          }
          i=0;
          while(i<26&&flag[i]==-1)
            i++;
          int save=findd(i);
          i++;
          for(i;i<26;i++)
          { 
              int temp=finddtill(i);
              if(temp!=-1&&save!=temp)
                  break;
          }
          if(i!=26){
            cout<<"The door cannot be opened."<<endl;
          }
          else
          {
              int checkstrt=0,checkend=0;
              for(i=0;i<26;i++)
              {
                  if(start[i]==ending[i]+1)
                      checkstrt++;
                  else if(start[i]+1==ending[i])
                      checkend++;
                  else if(start[i]>=ending[i]+1||start[i]+1<=ending[i]){
                    checkend=6;
                    break;
                  }
              }
              if((checkend==0&&checkstrt==0)||(checkstrt==1&&checkend==1))
                  cout<<"Ordering is possible."<<endl;
              else
                  cout<<"The door cannot be opened."<<endl;
          }
    }
    return 0;
}