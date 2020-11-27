#include <bits/stdc++.h>
#define PI 3.14159265358979323846
#define MAXINF (6e18L)
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
template<class T> void pr_vec(vector<T> &v, char ep=' '){int n=v.size();REP(ni,n){cout<<v[ni];if(ni!=n-1)cout<<ep;}cout<<endl;};
template<class T> inline bool chmin(T& a, T b){return a>b ? a=b, true : false;}
template<class T> inline bool chmax(T& a, T b){return a<b ? a=b, true : false;}
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll,ll> pll;

int main(void)
{
    int N,K;
    cin >> N >> K;
    vector<ll> x(N), y(N);
    REP(i, N) cin >> x[i] >> y[i];
    vector<ll> tx = x, ty = y;
    SORT(tx);SORT(ty);
    ll ans = MAXINF;
    REP(x1, N)REP(x2, x1)REP(y1, N)REP(y2, y1){
            ll minx = min(tx[x1],tx[x2]);
            ll maxx = max(tx[x1],tx[x2]);
            ll miny = min(ty[y1],ty[y2]);
            ll maxy = max(ty[y1],ty[y2]);
            int k = 0;
            REP(l, N)if(minx<=x[l]&&x[l]<=maxx&&miny<=y[l]&&y[l]<=maxy)k++;
            if(k>=K){
                chmin(ans, (maxx-minx)*(maxy-miny));
            }
    }
    pr(ans);
}