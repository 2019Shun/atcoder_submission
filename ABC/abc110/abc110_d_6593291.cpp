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

map<int, int> prime_factor(int n){
    map<int, int> res;
    for(int i = 2; i <= n; i++)
        while (n % i == 0){
            res[i]++;
            n /= i;
        }
    return res;
}

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
    int N,M;
    cin >> N >> M;

    mod_build();

    auto pf = prime_factor(M);

    ll ans = 1;
    for(auto&& i : pf){
        ans *= comb(i.second + N - 1, i.second);
        ans %= MOD;
    }

    pr(ans);

    // vector<ll> d;
    // for (ll i = 1; i*i <= M; i++) {
    //     if(M%i==0) {
    //         d.pb(i);
    //         if(i*i != M) d.pb(M/i);
    //     }
    // }
    // int n = d.size();
    // SORT(d);

    // map<int, int> dm;
    // REP(i, n){
    //     dm[d[i]] = i;
    // }

    // vector<vector<ll>> dp(N, vector<ll>(n, 0));
    // REP(i, N) dp[i][0] = 1;
    // REP(i, n) dp[0][i] = 1;

    // // Rep(i, 1, N){
    // //     REP(j, n){
    // //         REP(k, n){
    // //             if(d[j] * d[k] <= M && dm.count(d[j] * d[k]) == 1) 
    // //                 (dp[i][dm[d[j] * d[k]]] += dp[i-1][dm[d[j]]]) %= MOD;
    // //             if(d[j] * d[k] >= M) break;
    // //         }
    // //     }
    // // }
    // Rep(i, 1, N){
    //     Rep(j, 1, n){
    //         for (int k = 0; k <= j; k++) {
    //             if(d[j] % d[k] == 0){
    //                 dp[i][j] += dp[i-1][k];
    //             }
    //         }
    //         dp[i][j] %= MOD;
    //     }
    // }
    // pr(dp[N-1][n-1]);
}