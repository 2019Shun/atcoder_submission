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

// 遅延伝搬セグメント木
template <typename T,typename E>
struct LagySegmentTree{
    typedef function<T(T,T)> F;
    typedef function<T(T,E)> G;
    typedef function<E(E,E)> H;
    typedef function<E(E,ll)> P;
    int n;
    F f;
    G g;
    H h;
    P p;
    T d1;
    E d0;
    vector<T> dat;
    vector<E> laz;
    LagySegmentTree(int n_, F f, G g, H h, T d1, E d0, vector<T> v=vector<T>(), P p=[](E a,int b){return a;}):
        f(f),g(g),h(h),d1(d1),d0(d0),p(p){
        init(n_);
        if(n_==(int)v.size()) build(n_,v);
    }
    void init(int n_){
        n=1;
        while(n<n_) n*=2;
        dat.clear();
        dat.resize(2*n-1,d1);
        laz.clear();
        laz.resize(2*n-1,d0);
    }
    void build(int n_, vector<T> v){
        for(int i=0;i<n_;i++) dat[i+n-1]=v[i];
        for(int i=n-2;i>=0;i--) dat[i]=f(dat[i*2+1],dat[i*2+2]);
    }
    inline void eval(int len, int k){
        if(laz[k]==d0) return;
        if(k*2+1<n*2-1){
            laz[k*2+1]=h(laz[k*2+1],laz[k]);
            laz[k*2+2]=h(laz[k*2+2],laz[k]);
        }
        dat[k]=g(dat[k],p(laz[k],len));
        laz[k]=d0;
    }
    T update(int a,int b,E x,int k,int l,int r){
        eval(r-l,k);
        if(r<=a||b<=l) return dat[k];
        if(a<=l&&r<=b){
            laz[k]=h(laz[k],x);
            return g(dat[k],p(laz[k],r-l));
        }
        return dat[k]=f(update(a,b,x,k*2+1,l,(l+r)/2),
                update(a,b,x,k*2+2,(l+r)/2,r));
    }
    T update(int a,int b,E x){
        return update(a,b,x,0,0,n);
    }
    T query(int a,int b,int k,int l,int r){
        eval(r-l,k);
        if(r<=a||b<=l) return d1;
        if(a<=l&&r<=b) return dat[k];
        T vl=query(a,b,k*2+1,l,(l+r)/2);
        T vr=query(a,b,k*2+2,(l+r)/2,r);
        return f(vl,vr);
    }
    T query(int a,int b){
        return query(a,b,0,0,n);
    }
};

int main(void)
{
    int N;
    cin >> N;
    // LagySegmentTree<ll,ll> st(N,plus<ll>(), plus<ll>(), plus<ll>(), 0, 0, vector<ll>(N,0), multiplies<ll>());
    auto f = [](ll a, ll b){return max(a,b);};
    auto g = [](ll a, ll b){return a+b;};
    LagySegmentTree<ll,ll> st(114514, f, g, g, 0, 0);
    vector<pii> ST(N);
    REP(i, N){
        int s,t;
        cin >> s >> t;
        st.update(s, t, 1);
        ST[i].fi = s;
        ST[i].se = t;
    }

    ll ans = MAXINF;
    REP(i, N){
        st.update(ST[i].fi, ST[i].se, -1);
        ans = min(ans, st.query(0,114514));
        st.update(ST[i].fi, ST[i].se, 1);
    }
    pr(ans);
}