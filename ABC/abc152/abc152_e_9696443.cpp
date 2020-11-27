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

template<uint32_t mod>
struct ModInt{
    uint32_t a;
    ModInt& s(uint32_t vv){
        a=vv<mod?vv:vv-mod;
        return *this;
    }
 
    ModInt(int64_t x=0){s(x%mod+mod);}
 
    ModInt& operator+=(const ModInt &x){return s(a+x.a);}
    ModInt& operator-=(const ModInt &x){return s(a+mod-x.a);}
    ModInt& operator*=(const ModInt &x){
        a=uint64_t(a)*x.a%mod;
        return *this;
    }
    ModInt& operator/=(const ModInt &x){
        *this*=x.inv();
        return *this;
    }
 
    ModInt operator+(const ModInt &x)const{return ModInt(*this)+=x;}
    ModInt operator-(const ModInt &x)const{return ModInt(*this)-=x;}
    ModInt operator*(const ModInt &x)const{return ModInt(*this)*=x;}
    ModInt operator/(const ModInt &x)const{return ModInt(*this)/=x;}
    bool operator==(const ModInt &x)const{return a==x.a;}
    bool operator!=(const ModInt &x)const{return a!=x.a;}
    bool operator<(const ModInt &x)const{return a<x.a;}
 
    ModInt operator-()const{return ModInt()-*this;}
    ModInt pow(int64_t n)const{
        ModInt res(1),x(*this);
        while(n){
            if(n&1)res*=x;
            x*=x;
            n>>=1;
        }
        return res;
    }
 
    ModInt inv()const{return pow(mod-2);}
};
 
template<uint32_t mod>
istream& operator>>(istream& in,ModInt<mod>& a){
    return (in>>a.a);
}
template<uint32_t mod>
ostream& operator<<(ostream& out,const ModInt<mod>& a){
    return (out<<a.a);
}
using mint=ModInt<MOD>;

mint gcd(mint a, mint b) {
    if (b == 0) return a;
    return gcd(b, a.a % b.a);
}

mint lcm(mint a, mint b) {
    return a * (b / gcd(a, b));
}

map<ll, int> prime_factor(ll n){
    map<ll, int> res;
    for(ll i = 2; i*i <= n; i++){
        while (n % i == 0){
            res[i]++;
            n /= i;
        }
    }
    if(n != 1) res[n]++;
    return res;
}

int main(void)
{
    int N;
    cin >> N;
    vector<ll> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    map<ll, int> p;
    vector<map<ll, int>> pi(N);
    REP(i, N){
        pi[i] = prime_factor(A[i]);
        for(auto&& tmp: pi[i]){
            int tt = p[tmp.fi];
            p[tmp.fi] = max(tt, tmp.se);
        }
    }

    // mint ans;
    // REP(i, N){
    //     mint tmp_ans(1);
    //     // auto pi = prime_factor(A[i]);
    //     for(auto&& tmp: p){
    //         // tmp_ans *= (mint(tmp.fi) * mint(tmp.se - pi[tmp.fi])).a > 0 ? (mint(tmp.fi) * mint(tmp.se - pi[tmp.fi])) : 1;
    //         tmp_ans *= mint(tmp.fi).pow(tmp.se-pi[i][tmp.fi]);
    //     }
    //     ans += tmp_ans;
    // }

    mint T(1);
    for(auto&& pp : p) REP(i, pp.se) T *= pp.fi;

    mint ans;
	REP(i,N) ans+=T/A[i];


    pr(ans);
}