#include <bits/stdc++.h>
#define REP(i, n) for(int i=0;i<int(n);++i)
#define Yes(n) cout<<((n)?"Yes":"No")<<endl
using namespace std;
template<class A>void pr(A a){cout << (a) << endl;}
int main(void)
{
    char a,b;
    cin >> a >> b;
    if(a>b)pr('>');
    else if(a<b)pr('<');
    else if(a==b)pr('=');
}