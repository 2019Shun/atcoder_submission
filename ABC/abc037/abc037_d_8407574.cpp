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

int a[1010][1010];

int main(void)
{
    int H,W;
    cin >> H >> W;
    vector<pair<int, pii>> tmp;
    REP(i, H) REP(j, W) {
        cin >> a[i][j];
        tmp.pb(make_pair(a[i][j], pii(i, j)));
    }
    SORT(tmp);
    vector<vector<ll>> dp(H, vector<ll>(W, 1));

    for(auto &&t : tmp){
        int i = t.se.fi;
        int j = t.se.se;
        int dx[4]={-1,1,0,0}, dy[4]={0,0,-1,1};
        REP(k, 4){
            int x = i + dx[k];
            int y = j + dy[k];
            if(0 <= x && x < H && 0 <= y && y < W){
                if(a[i][j] < a[x][y]){
                    (dp[x][y] += dp[i][j]) %= MOD;
                }
            }
        }
    }
    ll ans = 0;
    REP(i, H) REP(j, W){    
        (ans += dp[i][j]) %= MOD;
    }
    pr(ans);
}