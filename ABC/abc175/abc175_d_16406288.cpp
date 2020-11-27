#include <bits/stdc++.h>
#define PI 3.14159265358979323846
#define MAXINF (1e18L+10L)
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
    int N;
    ll K;
    cin >> N >> K;
    vector<int> P(N);
    REP(i,N) cin >> P[i];
    REP(i,N) P[i]--;
    vector<ll> C(N);
    REP(i,N) cin >> C[i];
    
    vector<bool> ok(N);
    vector<vector<int>> vv;
    REP(i, N){
        if(ok[i]) continue;
        vector<int> v;
        v.pb(i);
        ok[i] = true;
        while(!(v.size()!=1&&P[v.back()]==i)){
            ok[P[v.back()]] = true;
            v.pb(P[v.back()]);
        }
        vv.pb(v);
    }

    int vn = vv.size();
    ll ans = -MAXINF;
    REP(i, vn){
        int n = vv[i].size();
        ll wa = C[vv[i][0]];
        Rep(j, 1, n) wa += C[vv[i][j]];

        REP(j, n){
            //jをスタート位置とした場合の計算
            ll tmp = 0;
            REP(k, n+1){
                tmp += C[vv[i][(j+k)%n]];
                if(k>=K) break;
                ll num = (K-k-1)/n;
                chmax(ans, tmp + (max(0ll, wa) * num));
            }
        }
    }

    pr(ans);
}