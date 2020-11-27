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

int main(void)
{
    string S;
    cin >> S;
    int K;
    cin >> K;
    int n = S.length();
    vector<vector<vector<ll>>> dp(n+1, vector<vector<ll>>(K+2, vector<ll>(2, 0)));

    dp[0][0][0] = 1;
    REP(i, n){
        REP(j, K+1){
            REP(d, 10){
                if(S[i]=='0' && d == 0) dp[i+1][j][0] += dp[i][j][0];
                else if((S[i]-'0') == d) dp[i+1][j+1][0] += dp[i][j][0];
                else if(d < (S[i]-'0')) {
                    if(d != 0) dp[i+1][j+1][1] += dp[i][j][0];
                    else dp[i+1][j][1] += dp[i][j][0];
                }
                
                if(d==0)dp[i+1][j][1] += dp[i][j][1];
                else dp[i+1][j+1][1] += dp[i][j][1];
            }
        }
    }
    pr(dp[n][K][0]+dp[n][K][1]);
}