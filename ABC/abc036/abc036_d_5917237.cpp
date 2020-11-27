#include <bits/stdc++.h>
#include <vector>
#include <numeric>
#define PI 3.14159265358979323846
#define MAXINF (1e18L)
#define INF (1e9)
#define EPS (1e-9)
#define MOD (1'000'000'007)
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
typedef long long ll;
typedef pair<int, int> pii;

int dpg[100010], dpf[100010];
vector<vector<int>> dp(100010);

ll g(ll x, ll p);

ll f(ll x, ll p){
    if(dpf[x]>0) return dpf[x];

    ll cg = 1;
    for(auto i: dp[x]){
        if(i==p)continue;
        cg *= g(i, x);
        cg %= MOD; 
    }
    if(cg==1) cg = 1;

    dpf[x] = (g(x,p) + cg) % MOD;
    return dpf[x];
}

ll g(ll x, ll p){
    if(dpg[x]>0)return dpg[x];

    ll cf = 1;   
    bool flag=true; 
    for(auto i: dp[x]){
        if(i==p)continue;
        cf *= f(i, x);
        cf %= MOD;
        flag = false;
    }
    if(flag) cf = 1;

    dpg[x] = cf;
    return dpg[x];
}

int main(void)
{
    int n;
    cin >> n;

    REP(i, n-1){
        int a,b;
        cin >> a >> b;
        a--;b--;
        dp[a].pb(b);
        dp[b].pb(a);
    }

    pr(f(0,-1));
}