#include <bits/stdc++.h>
#define PI 3.14159265358979323846
#define MAXINF (1e18L+9LL)
#define INF (1e9L)
#define EPS (1e-9)
#define MOD ((ll)(1e9+7))
#define REP(i, n) for(int i=0;i<int(n);++i)
#define REPA(x, v) for(auto&& x:v)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define RREP(i, n) for(int i=int(n)-1;i>=0;--i)
#define ALL(v) v.begin(),v.end()
#define FIND(v,x) (binary_search(ALL(v),(x)))
#define SORT(v) sort(ALL(v))
#define RSORT(v) sort(v.rbegin(),v.rend())
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
template<class T> void pr_vec(vector<T> &v, char ep=' '){int n=v.size();REP(ni,n){cout<<v[ni];if(ni!=n-1)cout<<ep;}cout<<endl;};
template<class T> inline bool chmin(T& a, T b){return a>b ? a=b, true : false;}
template<class T> inline bool chmax(T& a, T b){return a<b ? a=b, true : false;}
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll,ll> pll;

ll N,A,B,C,D;

ll f(ll n, map<ll,ll> &memo){
    if(n==0) return 0;
    if(n==1) return D;

    if(memo[n] > 0) return memo[n];

    ll res = MAXINF;

    if(n<res/D) chmin(res, D*n);
    chmin(res, D*abs(n-(n/2)*2)   +A+ f(n/2, memo));
    chmin(res, D*abs(n-((n+1)/2)*2) +A+ f((n+1)/2, memo));
    chmin(res, D*abs(n-(n/3)*3)   +B+ f(n/3, memo));
    chmin(res, D*abs(n-((n+2)/3)*3) +B+ f((n+2)/3, memo));
    chmin(res, D*abs(n-(n/5)*5)   +C+ f(n/5, memo));
    chmin(res, D*abs(n-((n+4)/5)*5) +C+ f((n+4)/5, memo));

    memo[n] = res;
    return res;
}

int main(void)
{
    int t;
    cin >> t;
    int n = 100;
    while(t--){
        cin >> N >> A >> B >> C >> D;

        map<ll, ll> memo;
        pr(f(N, memo));
    }
}