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

// セグメント木
// 半開区間[a,b)であることに注意
template <typename T>
struct SegmentTree{
    typedef function<T(T,T)> F;
    int n;
    F f;
    T d1;
    vector<T> dat;
    SegmentTree(){};
    SegmentTree(int n_,F f,T d1, vector<T> v=vector<T>()): f(f), d1(d1){
        init(n_);
        if(n_==(int)v.size()) build(n_,v);
    }
    void init(int n_){
        n=1;
        while(n<n_) n*=2;
        dat.clear();
        dat.resize(2*n-1,d1);
    }
    void build(int n_, vector<T> v){
        for(int i=0;i<n_;i++) dat[i+n-1]=v[i];
        for(int i=n-2;i>=0;i--)
        dat[i]=f(dat[i*2+1],dat[i*2+2]);
    }
    void update(int k, T a){
        k+=n-1;
        dat[k]=a;
        while(k>0){
        k=(k-1)/2;
        dat[k]=f(dat[k*2+1],dat[k*2+2]);
        }
    }
    inline T query(int a,int b){
        T vl=d1,vr=d1;
        for(int l=a+n,r=b+n;l<r;l>>=1,r>>=1) {
            if(l&1) vl=f(vl,dat[(l++)-1]);
            if(r&1) vr=f(dat[(--r)-1],vr);
        }
        return f(vl,vr);
    }
};

//一点更新・区間の最小値を求めるセグ木
SegmentTree<ll> get_range_min_query(int n){
    auto f = [](ll a, ll b){return min(a,b);};
    return SegmentTree<ll>(n, f, MAXINF);
}

int main(void)
{
    int N,Q;
    cin >> N >> Q;
    vector<map<ll,int>> Y(200010);
    vector<pll> ab(N);
    REP(i, N){
        cin >> ab[i].fi >> ab[i].se;
        Y[ab[i].se][ab[i].fi]++;
    }

    auto st = get_range_min_query(200010);
    REP(i, N){
        st.update(ab[i].se, (*Y[ab[i].se].rbegin()).fi);
    }

    REP(i, Q){
        int C,D;
        cin >> C >> D;C--;
        //移動前の値の更新
        Y[ab[C].se][ab[C].fi]--;
        if(Y[ab[C].se][ab[C].fi] == 0){
            Y[ab[C].se].erase(ab[C].fi);
        }
        if(Y[ab[C].se].empty()){
            st.update(ab[C].se, MAXINF);
        }
        else
        {
            st.update(ab[C].se, (*Y[ab[C].se].rbegin()).fi);        
        }
        
        ab[C].se = D;
        //移動先の更新
        Y[D][ab[C].fi]++;
        st.update(D, (*Y[D].rbegin()).fi);
        pr(st.query(0,200010));
    }
}