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

ll dfs(ll V, ll W, int n, int max_n, int max_w, const vector<int>& v, const vector<int>& w){
    if(W > max_w) return 0;
    if(n >= max_n) return V;
    return max(dfs(V+v[n], W+w[n], n+1, max_n, max_w, v, w), dfs(V, W, n+1, max_n, max_w, v, w));
}

int main(void)
{
    int n,W;
    cin >> n >> W;
    vector<int> v(n), w(n);
    int max_w = 0;
    REP(i, n){
        cin >> v[i] >> w[i];
        max_w = max(max_w, w[i]);
    }

    if(max_w <= 1000){
        vector<vector<ll>> dp(n+1, vector<ll>(W+1, 0));
        Rep(i,1,n+1){
            Rep(j,1,W+1){
                chmax(dp[i][j], dp[i-1][j]);
                if(j - w[i-1] >= 0){
                    chmax(dp[i][j], dp[i-1][j-w[i-1]] + v[i-1]);
                }
            }
        }
        pr(dp[n][W]);
    }else if(n <= 30){
        pr(dfs(0,0,0,n,W,v,w));
    }else{
        int total = 0;
        REP(i, n) total += v[i];
        vector<vector<ll>> dp(n+1, vector<ll>(total+1, 0));
        Rep(i,1,total+1) dp[0][i] = MAXINF;

        Rep(i, 0, n){
            Rep(j, 0, total+1){
                if(j - v[i] >= 0){
                    dp[i+1][j] = min(dp[i][j], dp[i][j-v[i]]+w[i]);
                }else{
                    dp[i+1][j] = dp[i][j];
                }
            }
        }
        int ans = 0;
        REP(i,total+1) if(dp[n][i]<= W) ans = i;
        pr(ans);
    }
}