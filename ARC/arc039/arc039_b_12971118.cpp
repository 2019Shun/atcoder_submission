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
template<class T> void pr_vec(vector<T> &v, char ep=' '){int n=v.size();REP(ni,n){cout<<v[ni];if(ni!=n-1)cout<<ep;}cout<<endl;};
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

mint factorial(int n){
    static map<int, mint> fa; 
    fa[0] = 1;
    if(fa.count(n) == 0){
        return fa[n] = factorial(n-1)*n;
    }
    return fa[n];
}

vector<mint> inv, fact, invfact;
void mod_build(int n = 200005){
    fact.assign(n+1, mint(1));
    inv.assign(n+1, mint(1));
    invfact.assign(n+1, mint(1));
    REP(i, n){
        fact[i+1] = fact[i] * mint(i+1);
        if(i > 0) inv[i+1] = mint() - inv[MOD % (i+1)] * mint(MOD / (i+1));
        invfact[i+1] = invfact[i] * inv[i+1];
    }
}
mint perm(int n, int k){
    if(n < 0 || k < 0 || k > n) return 0;
    return fact[n] * invfact[n-k];
}
mint comb(int n, int k){
    if(n<0 || k<0 || k>n) return 0;
    return (fact[n] * invfact[n-k]) * invfact[k];
}
// O(n)が間に合わなさそうなnに対応したcomb
// フェルマーの小定理と逆元を用いて計算
mint comb2(ll n, int k){
    mint X(n), Y(1);
    REP(i, k-1) {
        X *= n-i-1;
        Y *= i+2;
    }
    return X*Y.pow(MOD-2); 
}

int main(void)
{
    int N,K;
    cin >> N >> K;
    mod_build();
    if(N>K){
        pr(comb(N+K-1, K));return 0;
    }

    if((K%N)==0){
        pr(1);
        return 0;
    }

    int t = K/N;
    Rep(i, 1, N){
        if(i*t+(N-i)*(t+1) == K){
            pr(factorial(N)/(factorial(i)*factorial(N-i)));
        }
    }
    // pr(comb(N, K%N));
}