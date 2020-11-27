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

int main(void)
{
    int N,K;
    cin >> N >> K;
    int n = 0;
    vector<pll> A(N);
    REP(i, N){
        ll a;
        cin >> a;
        A[i] = {abs(a), a};
        if(a<0) n++;
    }
    if((K&1)&&n==N){
        //答えが負になる場合
        SORT(A);
        mint tmp(1);
        REP(i, K) tmp *= A[i].se;
        pr(tmp);
        return 0;
    }

    if(K==N){
        //N==Kの場合
        mint tmp(1);
        REP(i,N) tmp *= A[i].se;
        pr(tmp);
        return 0;
    }

    RSORT(A);
    mint ans(1);
    int tmp_n = 0, nl = -1, pl = -1;
    REP(i, K){
        ans *= A[i].se;
        if(A[i].se<0) tmp_n++, chmax(nl, i);
        else chmax(pl, i);
    }

    if(tmp_n&1){
        int ns = N, ps = N;
        Rep(i,K,N){
            if(A[i].se<0) chmin(ns, i);
            else chmin(ps, i);
        }
        if(pl==-1){
                ans /= A[nl].se;
                ans *= A[ps].se;
        }else if(ns!=N&&ps!=N){
            if(A[ns].se*A[nl].se < A[ps].se*A[pl].se){
                ans /= A[nl].se;
                ans *= A[ps].se;
            }else{
                ans /= A[pl].se;
                ans *= A[ns].se;
            }
        }else if(ns!=N){
                ans /= A[pl].se;
                ans *= A[ns].se;
        }else if(ps!=N){
                ans /= A[nl].se;
                ans *= A[ps].se;
        }
    }

    pr(ans);
}