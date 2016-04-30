#include<bits/stdc++.h>
int main(){int i,t=10,m,c;while(t--){c=0;char s[21];scanf("%s",s);for(i=0;i<strlen(s);i++)if(s[i]=='F'||s[i]=='L'||s[i]=='T'||s[i]=='D')c++;m=pow(2,c);printf("%d\n",m);}}