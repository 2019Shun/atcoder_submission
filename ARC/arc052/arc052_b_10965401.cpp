#include <bits/stdc++.h>
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

struct sui
{
    ll x, r, h;
    double s;
    sui(ll x, ll r, ll h) : x(x), r(r), h(h){
        s = r*r*h*PI/3.0;
    }
    double f(ll a, ll b){
        if(b <= x || (x+h) <= a) return 0.0;
        if(a <= x && (x+h) <= b) return s;
        if(x <= a && b <= (x+h)) return si((x+h)-a)-si((x+h)-b);
        if(x <= a) return si((x+h)-a);
        if(b <= (x+h)) return s-si((x+h)-b);
    }
    double si(ll h1){ //hは頂点からの距離
        return (((double)h1*h1*h1)/((double)h*h*h))*s;
    }
};


int main(void)
{
    int N,Q;
    cin >> N >> Q;
    vector<sui> s;
    REP(i, N){
        ll x,r,h;
        cin >> x >> r >> h;
        s.emplace_back(x,r,h);
    }
    vector<double> Ans;
    REP(i, Q){
        ll a,b;
        cin >> a >> b;
        double ans = 0;
        REP(j, N){
            ans += s[j].f(a, b);
        }
        Ans.pb(ans);
    }
    for(auto&& a : Ans) printf("%f\n", a);
}