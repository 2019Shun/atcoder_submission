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
    ll N,W;
    cin >> N >> W;
    vector<ll> w(N), v(N);
    REP(i, N) cin >> w[i] >> v[i];

    vector<vector<ll>> x(4, vector<ll>(1, 0));
    REP(i, N) x[w[i]-w[0]].pb(v[i]);

    RSORT(x[0]);RSORT(x[1]);RSORT(x[2]);RSORT(x[3]);

    ll ans = 0;
    ll v0,v1,v2,v3;
    REP(i, x[0].size()){
        v0 = 0;
        REP(iv, i) v0 += x[0][iv];
        REP(j, x[1].size()){
            v1 = 0;
            REP(jv, j) v1 += x[1][jv];
            REP(k, x[2].size()){
                v2 = 0;
                REP(kv, k) v2 += x[2][kv];
                REP(m, x[3].size()){
                    v3 = 0;
                    REP(mv, m) v3 += x[3][mv];
                    if(i*w[0]+j*(w[0]+1)+k*(w[0]+2)+m*(w[0]+3) <= W) chmax(ans, v0+v1+v2+v3);
                }
            }
        }
    }

    pr(ans);
}