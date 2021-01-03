#include <bits/stdc++.h>
#define PI 3.14159265358979323846
#define MAXINF (1e18L)
#define INF (1e9L)
#define EPS (1e-9)
#define MOD ((ll)(1e9+7))
#define REP(i, n) for(int i=0;i<int(n);++i)
#define REPA(x, v) for(auto&& x:v)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define RREP(i, n) for(int i=int(n)-1;i>=0;--i)
#define ALL(v) v.begin(),v.end()
#define FIND(v,x) (binary_search(ALL(v),(x)))
#define SORT(v) sort(ALL(v))
#define RSORT(v) sort(v.rbegin(),v.rend())
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

int main(void)
{
    int N,K;
    cin >> N >> K;
    vector<ll> A(N);
    vector<ll> am(N);
    REP(i,N) cin >> A[i];
    am[0] = A[0];
    Rep(i,1,N) chmax(am[i], max(am[i-1], A[i]));

    ll ans = MAXINF;
    REP(i, 1<<N){
        // if(__builtin_popcount(i)!=K) continue;

        vector<ll> t;
        REP(j, N){
            if(i&(1<<j)) t.pb(j);
        }

        if(t.size()!=K) continue;

        ll tmp = 0;
        // for(int j = 0; !(i&(1<<j)); j++){
        //     if(A[j] < t[0]) continue;
        //     tmp += A[j]-t[0]+1;
        //     t[0] = A[j]+1;
        // }
        // int id = __builtin_ctz(i);
        // if(id>0){
        //     tmp += max(0LL, am[id]-t[0]+1);
        //     t[0] = am[id]+1;
        // }
        // Rep(j, 1, K){
        //     tmp += max(0LL, t[j-1]-t[j]+1);
        //     t[j] = max(t[j], t[j-1]+1);
        // }
        ll maxHigh = 0;
        Rep(j, 0, K){
            maxHigh = max(maxHigh+1, am[t[j]]);
            tmp += maxHigh-A[t[j]];
        }
        chmin(ans, tmp);
    }

    pr(ans);
}