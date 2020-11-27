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

struct BIT{
    vector<ll> bit; //1-indexed
    int n;
    BIT(int n) : n(n), bit(vector<ll>(n+1, 0)) {}
    ll sum(int i){
        ll s = 0;
        while(i > 0){
            s += bit[i];
            i -= i & -i;
        }
        return s;
    }
    void add(int i, int x){
        while(i <= n){
            bit[i] += (ll)x;
            i += i & -i;
        }
    }
};

int main(void)
{
    int N,M;
    cin >> N >> M;
    vector<ll> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    BIT bitA(N);
    BIT bitB(N);
    SORT(A);
    REP(i, N){
        bitA.add(i+1, A[i]);
    }
    vector<pii> cb(M);
    REP(i, M){
        cin >> cb[i].se >> cb[i].fi;
    }
    RSORT(cb);
    int it = 1;
    REP(i, M){
        REP(j, cb[i].se){
            bitB.add(it++, cb[i].fi);
            if(it>N)break;
        }
        if(it>N)break;
    }
    
    ll ans = bitA.sum(N);
    REP(i, N){
        ans = max(ans, bitA.sum(N) - bitA.sum(i+1) + bitB.sum(i+1));
    }
    pr(ans);

    // int N,M;
    // cin >> N >> M;
    // vector<ll> A(N);
    // vector<pii> AI(N);
    // for (int i = 0; i < N; i++) {
    //     cin >> A[i];
    //     AI[i].fi = A[i];
    //     AI[i].se = i+1;
    // }
    // BIT bit(N);
    // REP(i, N){
    //     bit.add(i+1, A[i]);
    // }
    // vector<pii> cb(M);
    // REP(i, M){
    //     cin >> cb[i].se >> cb[i].fi;
    // }
    // SORT(AI);
    // RSORT(cb);
    // int ait = 0;
    // REP(i, M){
    //     if(ait == N) break;
    //     REP(j, cb[i].se){
    //         if(AI[ait].fi < cb[i].fi){
    //             bit.add(AI[ait].se, cb[i].fi - A[AI[ait].se-1]);
    //             ait++;
    //         }else{
    //             break;
    //         }
    //     }
    // }
    // pr(bit.sum(N));
    // return 0;
}