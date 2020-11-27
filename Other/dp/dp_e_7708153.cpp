#include <bits/stdc++.h>
#include <vector>
#include <numeric>
#define PI 3.14159265358979323846
#define MAXINF (1e18L)
#define INF (1e9L+10)
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

int main(void)
{
    int N,W;
    cin >> N >> W;
    vector<int> w(N), v(N);
    REP(i, N){
        cin >> w[i] >> v[i];
    }

    vector<vector<ll>> dp(100010, vector<ll>(N+1, INF));
    REP(i, N+1){
        dp[0][i] = 0;
    }

    Rep(i, 1, 100005){
        Rep(j, 1, N+1){
            chmin(dp[i][j], dp[i][j-1]);
            if(i-v[j-1] >= 0){
                chmin(dp[i][j], dp[i-v[j-1]][j-1] + w[j-1]);
            }
        }
    }
    ll ans = 0;
    REP(i, 100005){
        Rep(j, 1, N+1){
            if(dp[i][j] != 0 && dp[i][j]<=W) ans = max(ans, (ll)i);
        }
    }
    pr(ans);
}