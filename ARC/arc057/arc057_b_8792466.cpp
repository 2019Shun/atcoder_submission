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
template<class A>int pr(A a){cout << (a) << endl; return 0;}
template<class A,class B>int pr(A a,B b){cout << a << " "  ;pr(b);}
template<class A,class B,class C>int pr(A a,B b,C c){cout << a << " " ;pr(b,c);}
template<class A,class B,class C,class D>int pr(A a,B b,C c,D d){cout << a << " " ;pr(b,c,d);}
template<class T> inline bool chmin(T& a, T b){return a>b ? a=b, true : false;}
template<class T> inline bool chmax(T& a, T b){return a<b ? a=b, true : false;}
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll,ll> pll;

int main(void)
{
    ll N,K;
    cin >> N >> K;
    vector<ll> a(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }

    vector<vector<ll>> dp(N+1, vector<ll>(N+1, MAXINF));
    REP(i,N+1) dp[i][0] = 0;
    dp[1][1] = 1;
    ll S = a[0];
    Rep(i, 2, N+1){
        Rep(j, 1, i+1){
            // dp[i][j] = min(dp[i-1][j], dp[i-1][j-1] + (((S+a[i-1])*dp[i-1][j-1])/S-dp[i-1][j-1])+1);
            // ll p = (ll)((dp[i-1][j-1] * (double)(S+a[i-1]) / (double)S) - dp[i-1][j-1]) + 1;
            ll p = (ll)((dp[i-1][j-1] * (double)(S+a[i-1]) / (double)S) - dp[i-1][j-1]) + 1;
            if(p <= a[i-1])
                dp[i][j] = min(dp[i][j], dp[i-1][j-1] + p);
            dp[i][j] = min(dp[i][j], dp[i-1][j]);
        }
        S += a[i-1];
    }

    if(S==0) return pr(0);
    if(S==K) return pr(1);

    int ans = 0;
    REP(i, N+1){
        if(dp[N][i] <= K) ans = max(ans, i);
    }

    pr(ans);
}