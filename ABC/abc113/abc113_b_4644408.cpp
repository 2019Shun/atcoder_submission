#include <bits/stdc++.h>
#include <vector>
#include <numeric>
#define PI 3.14159265358979323846
#define MAXINF 1e18L
#define MININF -1e18L
#define REP(i, n) for(int i=0;i<int(n);++i)
#define RREP(i, n) for(int i=int(n)-1;i>=0;--i)
#define ALL(v) v.begin(),v.end()
#define SORT(v) sort(ALL(v))
#define DEBUG(x) cerr<<#x<<": "<<x<<endl;
#define DEBUG_VEC(v) cerr<<#v<<":";for(int i=0;i<v.size();i++) cerr<<" "<<v[i]; cerr<<endl
#define pb push_back
using namespace std;
template<class A>void pr(A a){cout << (a) << endl;}
template<class A,class B>void pr(A a,B b){cout << a << " "  ;pr(b);}
template<class A,class B,class C>void pr(A a,B b,C c){cout << a << " " ;pr(b,c);}
template<class A,class B,class C,class D>void pr(A a,B b,C c,D d){cout << a << " " ;pr(b,c,d);}
typedef long long ll;
typedef pair<int, int> intint;

int main(void)
{
    int n;
    cin >> n;
    int t,a;
    cin >> t >> a;
    double min_v = 100000000;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        // min_v = min(min_v, abs((t - tmp * 0.006) - a);
        if(min_v > abs(a - (t - tmp * 0.006))){
            ans = i + 1;
            min_v = abs(a - (t - tmp * 0.006));
        }
    }

    pr(ans);
}