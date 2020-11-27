#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
const int INF = int (1e9) + int (1e5);
const ll INFL = ll(2e18) + ll(1e10);
const ui MOD = 1E9 + 7;
const double EPS = 1e-9;
#define FOR(i,n) for (int i=0;i<(n);++i)
#define ROF(i,x) for(int i = (x) ; i >= 0 ; --i)
#define MP make_pair
#define ALL(a) (a).begin(),(a).end()
#define ODD(x) (((x)&1)==0?(0):(1))
#define sign(x) ((x > 0) - (x < 0))
#define dbg(x) cerr << #x"= " << x << endl
 
std::mt19937_64  generator(std::chrono::system_clock::now().time_since_epoch().count());
 
inline ll powmod(ll a,ll b,ll mod) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a, ll b) { return a ? gcd(b%a, a): b; }
ll lcm(ll a, ll b) { return a / gcd(a,b) * b; }
 
 
void READ(bool _local){
    ios_base::sync_with_stdio(false); cin.tie(0);
#ifdef _DEBUG
    if (_local)
        freopen ("in.txt", "r", stdin);
#endif
}
 
int bf(int n,int m,vi &a){
    int ret=0;
    for(int x=1;x<=m;++x){
        bool doit=true;
        for(int j=0;j<n;++j){
            if (x < a[j]/2) {doit=false;break;}
            if ((x-a[j]/2)%a[j]!=0) {doit=false;break;}
        }
        if (doit) ++ret;
    }
    return ret;
}
int main() {
    READ(1);
    int n,m;cin>>n>>m;
    vi a(n);
    FOR(i,n) {cin>>a[i];}
 //   dbg(bf(n,m,a));
    FOR(i,n) a[i] /= 2;
    ll r=a[0];
    for(int i=1;i<n;++i){
        if (r>m) break;
        r=lcm(r,a[i]);
    }
    if (r>m){cout << 0;return 0;}
    for(int i=0;i<n;++i){
        int y=r/a[i];
        if (y%2==0){cout << 0 ; return 0;}
    }
    ll ret=m/r;
    if (ret%2==0) ret/=2;
    else ret = ret/2+1;
    cout << ret << endl;
 
    return 0;
}