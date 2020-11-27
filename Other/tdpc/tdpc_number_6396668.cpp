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

struct mint {
  ll x;
  mint(ll x=0):x(x%MOD){}
  mint& operator+=(const mint a) {
    if ((x += a.x) >= MOD) x -= MOD;
    return *this;
  }
  mint& operator-=(const mint a) {
    if ((x += MOD-a.x) >= MOD) x -= MOD;
    return *this;
  }
  mint& operator*=(const mint a) {
    (x *= a.x) %= MOD;
    return *this;
  }
  mint operator+(const mint a) const {
    mint res(*this);
    return res+=a;
  }
  mint operator-(const mint a) const {
    mint res(*this);
    return res-=a;
  }
  mint operator*(const mint a) const {
    mint res(*this);
    return res*=a;
  }
  mint pow(ll t) const {
    if (!t) return 1;
    mint a = pow(t>>1);
    a *= a;
    if (t&1) a *= *this;
    return a;
  }
 
  // for prime mod
  mint inv() const {
    return pow(MOD-2);
  }
  mint& operator/=(const mint a) {
    return (*this) *= a.inv();
  }
  mint operator/(const mint a) const {
    mint res(*this);
    return res/=a;
  }
};

int main(void)
{
    int d;
    cin >> d;
    string n;
    cin >> n;
    int l = n.size();
    
    vector<vector<vector<ll>>> dp(l+1, vector<vector<ll>>(d, vector<ll>(2, 0)));

    dp[l][0][1] = 1;
    for(int i = l; i > 0; i--){
        for(int j = 0; j < d; j++){
            for(int k = 0; k < 2; k++){
                for(int m = 0; m <= 9; m++){
                    // bool leq = m < (n[i-1] - '0') || (k == 1 && m == (n[i-1] - '0'));
                    bool leq = m < (n[i-1] - '0') || (k == 1 && m <= (n[i-1] - '0'));
                    dp[i-1][(j + m) % d][leq] += dp[i][j][k];
                    dp[i-1][(j + m) % d][leq] %= MOD;
                }
            }
        }
    }
    pr(dp[0][0][1]-1);
}

//未満フラグを考慮しない場合
// int main(void)
// {
//     int d;
//     cin >> d;
//     string n;
//     cin >> n;
//     int l = n.size();
//     vector<vector<ll>> dp(l+1, vector<ll>(d, 0));
//     dp[l][0] = 1;
//     for(int i = l; i > 0; i--){
//         for(int j = 0; j < d; j++){
//             for(int m = 0; m <= 9; m++){
//                 dp[i-1][(j + m) % d] += dp[i][j];
//             }
//         }
//     }
//     pr(dp[0][0]-1);
// }