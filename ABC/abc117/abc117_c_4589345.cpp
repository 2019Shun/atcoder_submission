#include <bits/stdc++.h>
#include <vector>
#include <numeric>
using namespace std;
#define PI 3.14159265358979323846
#define MAXINF 1e18L
#define MININF -1e18L
#define REP(i, n) for(int i=0;i<int(n);++i)
#define RREP(i, n) for(int i=int(n)-1;i>=0;--i)
#define ALL(v) v.begin(),v.end()
#define SORT(v) sort(ALL(v))
#define RSORT(v) sort(ALL(v), greater<int>())
#define DEBUG(x) cerr<<#x<<": "<<x<<endl;
#define DEBUG_VEC(v) cerr<<#v<<":";for(int i=0;i<v.size();i++) cerr<<" "<<v[i]; cerr<<endl
#define pb push_back
template<class A>void pr(A a){cout << (a) << endl;}
template<class A,class B>void pr(A a,B b){cout << a << " "  ;pr(b);}
template<class A,class B,class C>void pr(A a,B b,C c){cout << a << " " ;pr(b,c);}
template<class A,class B,class C,class D>void pr(A a,B b,C c,D d){cout << a << " " ;pr(b,c,d);}
typedef long long ll;
typedef pair<int, int> intint;

int main(void)
{
    int n,m;
    cin >> n >> m;
    vector<int> x(m);
    for (int i = 0; i < m; i++) {
        cin >> x[i];
    }

    if(n >= m){
        pr(0);
        return 0;
    }

    SORT(x);
    vector<int> diff(m - 1);
    for (int i = 0; i < m-1; i++) {
        diff[i] = (x[i+1] - x[i]);
    }
    RSORT(diff);

    int ans = x[x.size() - 1] - x[0];

    REP(i, n - 1){
        ans -= diff[i];
    }
    pr(ans);
}