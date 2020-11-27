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

int main(void)
{
    ll H,W,K;
    cin >> H >> W >> K;
    vector<vector<ll>> dp(H+1, vector<ll>(W, 0));
    dp[0][0] = 1;
    if(W==1){
        pr(1);
        return 0;
    }

    REP(h, H){
        REP(w, W){
            for (int i = 0; i < 1<<(W-1); i++) {
                bool flag = false;
                for (int j = 0; j < W-2; j++) {
                    if(i&(1<<j) && i&(1<<(j+1))){
                        flag = true;
                        break;
                    }
                }
                if(flag)continue;//正しい網くじでない

                flag = true;
                if(w != 0){
                    if(i&(1<<(w-1))){
                        (dp[h+1][w-1] += dp[h][w]) %= MOD; 
                        flag = false;
                    }
                }
                if(w != W-1){
                    if(i&(1<<(w))){
                        (dp[h+1][w+1] += dp[h][w]) %= MOD; 
                        flag = false;
                    }
                }
                if(flag){
                    (dp[h+1][w] += dp[h][w]) %= MOD; 
                }
            }
        }
    }
    pr(dp[H][K-1]);
}