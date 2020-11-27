#include <bits/stdc++.h>
#include <vector>
#include <numeric>
#define PI 3.14159265358979323846
#define MAXINF (1e18L)
#define INF (1e9L)
#define EPS (1e-9)
#define MOD ((ll)(998244353))
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

// template<typename T,T MOD = 1000000007>
// struct Mint{
//   static constexpr T mod = MOD;
//   T v;
//   Mint():v(0){}
//   Mint(signed v):v(v){}
//   Mint(long long t){v=t%MOD;if(v<0) v+=MOD;}
 
//   Mint pow(long long k){
//     Mint res(1),tmp(v);
//     while(k){
//       if(k&1) res*=tmp;
//       tmp*=tmp;
//       k>>=1;
//     }
//     return res;
//   }
 
//   static Mint add_identity(){return Mint(0);}
//   static Mint mul_identity(){return Mint(1);}
 
//   Mint inv(){return pow(MOD-2);}
 
//   Mint& operator+=(Mint a){v+=a.v;if(v>=MOD)v-=MOD;return *this;}
//   Mint& operator-=(Mint a){v+=MOD-a.v;if(v>=MOD)v-=MOD;return *this;}
//   Mint& operator*=(Mint a){v=1LL*v*a.v%MOD;return *this;}
//   Mint& operator/=(Mint a){return (*this)*=a.inv();}
 
//   Mint operator+(Mint a) const{return Mint(v)+=a;}
//   Mint operator-(Mint a) const{return Mint(v)-=a;}
//   Mint operator*(Mint a) const{return Mint(v)*=a;}
//   Mint operator/(Mint a) const{return Mint(v)/=a;}
 
//   Mint operator-() const{return v?Mint(MOD-v):Mint(v);}
 
//   bool operator==(const Mint a)const{return v==a.v;}
//   bool operator!=(const Mint a)const{return v!=a.v;}
//   bool operator <(const Mint a)const{return v <a.v;}
 
//   static Mint comb(long long n,Int k){
//     Mint num(1),dom(1);
//     for(Int i=0;i<k;i++){
//       num*=Mint(n-i);
//       dom*=Mint(i+1);
//     }
//     return num/dom;
//   }
// };
// template<typename T,T MOD> constexpr T Mint<T, MOD>::mod;
// template<typename T,T MOD>
// ostream& operator<<(ostream &os,Mint<T, MOD> m){os<<m.v;return os;}

ll  mult(long long  a , long long  b) {
    return (a%MOD*b%MOD)%MOD;
}

int main(void)
{
    ll N;
    cin >> N;
    map<ll, ll> m;
    bool flag = false;
    REP(i, N){
        ll a;
        cin >> a;
        m[a]++;
        if(i!=0&&a==0) flag = true;
    }

    if(flag){
        pr(0);
        return 0;
    }

    if(m[0] != 1){
        pr(0);
        return 0;
    }

    ll ans = 1;
    // map<ll, ll> kai;
    // kai[0] = 1;
    // for (ll i = 1; i <= N; i++) {
    //     kai[i] = kai[i-1] * i;
    //     kai[i] %= 998244353;
    // }

    for (ll i = 2; i <= N; i++) {
        if(m.count(i) == 0){
            continue;
        }
        // ll p = 1;
        // REP(j, m[i]) (p *= m[i-1]) %= MOD;
        for(ll j = 0; j < m[i]; j++) ans = mult(ans , m[i-1]);
        // p %= 998244353;
        // p = kai[m[i] + (m[i-1]-1)] / ((kai[m[i-1]-1] * m[i]) % 998244353);
        // (ans *= p) %= MOD;
    }

    pr(ans%998244353);
}