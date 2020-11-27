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

// // インスタンスを作成する時は ST st<ll>でTの型を指定してあげる
// template <typename T>
// struct ST{
//     using F = function<T(T,T)>;
//     F f;
//     vector<T> dat;
//     int n;
//     T ti;
//     ST(F f, int n_, T init = INF) : f(f), ti(init) {
//         n = 1;
//         while(n < n_) n <<= 1;
//         dat.assign(n << 1, init);
//     }
//     ST(int n_, T init = INF) : ST([](ll a, ll b){return (ll)max(a, b);}, n_, init){}

//     void update(int k, T a){
//         k += n -1;
//         dat[k] = a;
//         while(k > 0){
//             k = (k - 1) / 2;
//             dat[k] = f(dat[k * 2 + 1], dat[k * 2 + 2]);
//         }
//     }
//     // [a, b)
//     // 外部からはquery(a,b,0,0,st.n)で呼び出す(インスタンス変数がst)
//     T query(int a, int b, int k, int l, int r){
//         if(r <= a || b <= l) return ti;
//         if(a <= l && r <= b) return dat[k];
//         else{
//             T vl = query(a,b,k * 2 + 1, l, (l + r) / 2);
//             T vr = query(a,b,k * 2 + 2, (l + r) / 2, r);
//             return f(vl, vr);
//         }
//     }
// };

// インスタンスを作成する時は ST st<ll>でTの型を指定してあげる
template <typename T>
struct ST{
    using F = function<T(T,T)>;
    F f;
    vector<T> dat;
    int n;
    T ti;
    ST(F f, int n_, T init = INF) : f(f), ti(init) {
        n = 1;
        while(n < n_) n <<= 1;
        dat.assign(n << 1, init);
    }
    ST(int n_, T init = INF) :            ST([](ll a, ll b){return (ll)max(a, b);}, n_, init){} //RMQ

    void update(int k, T a){
        k += n -1;
        dat[k] = a;
        while(k > 0){
            k = (k - 1) / 2;
            dat[k] = f(dat[k * 2 + 1], dat[k * 2 + 2]);
        }
    }
    // [a, b)
    // 外部からはquery(a,b,0,0,st.n)で呼び出す(インスタンス変数がst)
    T query(int a, int b, int k, int l, int r){
        if(r <= a || b <= l) return ti;
        if(a <= l && r <= b) return dat[k];
        else{
            T vl = query(a,b,k * 2 + 1, l, (l + r) / 2);
            T vr = query(a,b,k * 2 + 2, (l + r) / 2, r);
            return f(vl, vr);
        }
    }
};

int main(void)
{
    ll N, T;
    cin >> N >> T;
    vector<ll> A(N);
    ST<ll> st(N, 0);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        st.update(i, A[i]);
    }
    map<ll, int> mp;
    REP(i, N-1){
        ll sa = st.query(i+1, N, 0, 0, st.n) - A[i];
        if(sa < 0) continue;
        mp[sa]++;
    }

    pr((*mp.rbegin()).se);
}