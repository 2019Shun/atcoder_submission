#include <bits/stdc++.h>
#define REP(i, n) for(int i=0;i<int(n);++i)
#define Yes(n) cout<<((n)?"Yes":"No")<<endl
using namespace std;
template<class A>void pr(A a){cout << (a) << endl;}
int main(void)
{
    int a,b,c;
    cin >> a >> b >> c;
    if(a!=b && a != c) pr(a);
    if(a!=b && b != c) pr(b);
    if(c!=a && b != c) pr(c);
}