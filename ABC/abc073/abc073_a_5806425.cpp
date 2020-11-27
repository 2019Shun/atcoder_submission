#include <bits/stdc++.h>
#define REP(i, n) for(int i=0;i<int(n);++i)
#define Yes(n) cout<<((n)?"Yes":"No")<<endl
using namespace std;
template<class A>void pr(A a){cout << (a) << endl;}
int main(void)
{
    int n;
    cin >> n;
    Yes((n % 10 == 9) || (n / 10) == 9);
}