#include<bits/stdc++.h>
using namespace std;
 
#define FOR(n) for(int i=0;i<n;i++)
#define ll long long
 
using namespace std;
int main()
{ int n,k,r,s,p;int sum=0;char l[100001];
 cin>>n>>k;
 cin>>r>>s>>p;
 char t[100001];
 cin>>t;
 map<char,char> g;
 g.insert({'s','r'});
 g.insert({'r','p'});
 g.insert({'p','s'});
 map<char,int> g1;
 g1.insert({'s',s});
 g1.insert({'r',r});
 g1.insert({'p',p});
 
FOR(n)
{if(i<k)
{l[i]=g[t[i]];
  sum+=g1[g[t[i]]];}
 else
 {if(l[i-k]==g[t[i]])
 {
   sum=sum+0;}
  else
  { l[i]=g[t[i]];
    sum+=g1[g[t[i]]];}
  
 }
 
 
 }
 
 
 
 
cout<<sum;
 
return 0;
}