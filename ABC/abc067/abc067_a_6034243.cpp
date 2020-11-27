#include <bits/stdc++.h>
#define REP(i, n) for(int i=0;i<int(n);++i)
#define Yes(n) cout<<((n)?"Yes":"No")<<endl
using namespace std;
template<class A>void pr(A a){cout << (a) << endl;}
int main(void)
{
    int a,b;
    cin >> a >> b;
    if(a % 3 == 0 || b % 3 == 0 || (a+b) % 3 == 0)pr("Possible");
    else pr("Impossible");
}