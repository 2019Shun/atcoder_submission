#include <bits/stdc++.h>
#include <vector>
#include <numeric>
#define PI 3.14159265358979323846
#define MAXINF (1e18L)
#define INF (1e9L)
#define EPS (1e-9)
#define MOD ((ll)(1e9+7))
#define REP(i, n) for(int i=0;i<int(n);++i)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define RREP(i, n) for(int i=int(n)-1;i>=0;--i)
#define ALL(v) v.begin(),v.end()
#define FIND(v,x) (binary_search(ALL(v),(x)))
#define SORT(v) sort(ALL(v))
#define RSORT(v) sort(ALL(v));reverse(ALL(v))
#define DEBUG(x) cerr<<#x<<": "<<x<<endl;
#define DEBUG_VEC(v) cerr<<#v<<":";for(int i=0;i<v.size();i++) cerr<<" "<<v[i]; cerr<<endl
#define Yes(n) cout<<((n)?"Yes":"No")<<endl
#define YES(n) cout<<((n)?"YES":"NO")<<endl
#define pb push_back
#define fi first
#define se second
using namespace std;
template<class A>void pr(A a){cout << (a) << endl;}
template<class A,class B>void pr(A a,B b){cout << a << " "  ;pr(b);}
template<class A,class B,class C>void pr(A a,B b,C c){cout << a << " " ;pr(b,c);}
template<class A,class B,class C,class D>void pr(A a,B b,C c,D d){cout << a << " " ;pr(b,c,d);}
template<class T> inline bool chmin(T& a, T b){return a>b ? a=b, true : false;}
template<class T> inline bool chmax(T& a, T b){return a<b ? a=b, true : false;}
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll,ll> pll;

int main(void)
{
    int A,B,Q;
    cin >> A >> B >> Q;
    vector<ll> s(A), t(B), x(Q);
    REP(i, A) cin >> s[i];
    REP(i, B) cin >> t[i];
    REP(i, Q) cin >> x[i];

    REP(i, Q){
        ll s11, s12, t11, t12;
        int it = lower_bound(ALL(s), x[i]) - s.begin();
        if(it == 0){
            s11 = -MAXINF;
            s12 = s[it];
        }else if(it == A){
            s11 = s[it-1];
            s12 = MAXINF;
        }else{
            s11 = s[it-1];
            s12 = s[it];
        }
        it = lower_bound(ALL(t), x[i]) - t.begin();
        if(it == 0){
            t11 = -MAXINF;
            t12 = t[it];
        }else if(it == B){
            t11 = t[it-1];
            t12 = MAXINF;
        }else{
            t11 = t[it-1];
            t12 = t[it];
        }
        ll ans = MAXINF;
        if(s11 < t11 && t11 < x[i]) ans = min(ans, x[i] - s11);
        if(t11 < s11 && s11 < x[i]) ans = min(ans, x[i] - t11);
        if(s11 < x[i] && x[i] < t12) ans = min(ans, t12 - s11 + min(t12 - x[i], x[i] - s11));
        if(t11 < x[i] && x[i] < s12) ans = min(ans, s12 - t11 + min(s12 - x[i], x[i] - t11));
        if(x[i] < s12 && s12 < t12) ans = min(ans, t12 - x[i]);
        if(x[i] < t12 && t12 < s12) ans = min(ans, s12 - x[i]);
        pr(ans);
    }
}