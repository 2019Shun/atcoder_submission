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

vector<ll> inv, fact, invfact;
void mod_build(int n = 101010){
    fact.resize(n+1);
    inv.resize(n+1);
    invfact.resize(n+1);
    fact[0] = inv[0] = invfact[0] = 1;
    inv[1] = 1;
    REP(i, n){
        fact[i+1] = fact[i] * (i+1) % MOD;
        if(i > 0) inv[i+1] = MOD - inv[MOD % (i+1)] * (MOD / (i+1)) % MOD;
        invfact[i+1] = invfact[i] * inv[i+1] % MOD;
    }
}
ll perm(int n, int k){
    if(n < 0 || k < 0 || k > n) return 0;
    return fact[n] * invfact[n-k] % MOD;
}
ll comb(int n, int k){
    if(n<0 || k<0 || k>n) return 0;
    return (fact[n] * invfact[n-k] % MOD) * invfact[k] % MOD;
}

int main(void)
{
    int N;
    cin >> N;
    map<int, ll> s;
    REP(i, N){
        string si;
        cin >> si;
        switch (si[0])
        {
        case 'M':
            s[0]++;
            break;
        case 'A':
            s[1]++;
            break;
        case 'R':
            s[2]++;
            break;
        case 'C':
            s[3]++;
            break;
        case 'H':
            s[4]++;
            break;
        }
    }
    ll ans = 0;
    int n = s.size();
    if(n<3){
        pr(0);
        return 0;
    }
    vector<ll> v(n);
    int it = 0;
    for(auto&& si : s) v[it++] = si.se;
    REP(i, 1<<n){
        if(__builtin_popcount(i)==3){
            ll t = 1;
            REP(j, n){
                if(i & (1<<j)) (t *= v[j]);
            }
            (ans += t);
        }
    }

    pr(ans);
}