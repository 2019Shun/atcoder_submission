#include <bits/stdc++.h>
#define REP(i, n) for(int i=0;i<int(n);++i)
#define Yes(n) cout<<((n)?"Yes":"No")<<endl
#define ALL(v) v.begin(),v.end()
#define FIND(v,x) (binary_search(ALL(v),(x)))
#define SORT(v) sort(ALL(v))
using namespace std;
template<class A>void pr(A a){cout << (a) << endl;}
int main(void)
{
    vector<int> a(3);
    for (int i = 0; i < 3; i++) {
        cin >> a[i];
    }
    SORT(a);
    pr(a[0]+ a[1]);
}