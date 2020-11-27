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
void mod_build(int n = 1010100){
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
ll perm(ll n, ll k){
    if(n < 0 || k < 0 || k > n) return 0;
    return fact[n] * invfact[n-k] % MOD;
}
ll comb(ll n, ll k){
    if(n<0 || k<0 || k>n) return 0;
    return (fact[n] * invfact[n-k] % MOD) * invfact[k] % MOD;
}

int main(void)
{
    ll X,Y;
    cin >> X >> Y;
    
    mod_build();

    // if((X&1)==0 && (Y&1)==0){
    //     pr(0);
    //     return 0;
    // }

    if(X<Y){
        int tmp = X;
        X = Y;
        Y = tmp;
    }

    if(X==Y && (X%3) == 0){
        pr(comb((X/3)*2, Y/3) % MOD);
    }else{
        REP(i, 1000002){
            ll x = X + i;
            ll y = Y - i;
            if(y < 0){
                pr(0);
                break;
            }
            if(x == y*2){
                pr(comb(x/2, i) % MOD);
                break;
            }
        }
        return 0;
    }

}