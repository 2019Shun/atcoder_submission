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
    int N;
    cin >> N;
    vector<vector<int>> D(N, vector<int>(N));
    REP(i, N)REP(j, N) cin >> D[i][j];
    int Q;
    cin >> Q;
    vector<int> P(Q);
    REP(i,Q) cin >> P[i];
    
    vector<vector<int>> t(N+1, vector<int>(N+1));
    
    REP(i, N)REP(j, N){
        // t[i+1][j+1] += D[i][j]; 
        // if(i!=N-1) t[i+2][j+1] += D[i][j]; 
        // if(j!=N-1) t[i+1][j+2] += D[i][j]; 
        t[i+1][j+1] = (D[i][j] + t[i][j+1] + t[i+1][j] - t[i][j]);
    }

    vector<pii> ans;
    Rep(x1, 1, N+1)Rep(y1, 1, N+1){
        Rep(x2, x1, N+1)Rep(y2, y1, N+1){
            int d = (x2-x1+1)*(y2-y1+1);
            int v = t[x2][y2] - t[x2][y1-1] - t[x1-1][y2] + t[x1-1][y1-1];
            ans.pb({v, d});    
        }
    }

    RSORT(ans);
    int n = ans.size();

    REP(i, Q){
        int a = 0;
        REP(j, n){
            if(ans[j].se <= P[i]) chmax(a, ans[j].fi);
        }
        pr(a);
        // pr(-(*upper_bound(ALL(ans), pii(P[i], -INF))).se);
    }
}