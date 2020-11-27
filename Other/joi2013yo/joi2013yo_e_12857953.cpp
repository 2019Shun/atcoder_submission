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
template<class T> void pr_vec(vector<T> &v, char ep=' '){int n=v.size();REP(ni,n){cout<<v[ni];if(ni!=n-1)cout<<ep;}cout<<endl;};
template<class T> inline bool chmin(T& a, T b){return a>b ? a=b, true : false;}
template<class T> inline bool chmax(T& a, T b){return a<b ? a=b, true : false;}
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll,ll> pll;

// 座標圧縮
// xs:領域の始点配列，xe：領域の終点配列
int compress(vector<ll> &xs, vector<ll> &xe, map<int,ll> &xm){
    int n = xs.size();
    vector<ll> x;
    REP(i,n){
        x.pb(xs[i]);
        x.pb(xe[i]);
    }
    SORT(x);
    x.erase(unique(ALL(x)), x.end()); 
    REP(i, n){
        int s = lower_bound(ALL(x), xs[i]) - x.begin();
        xm[s] = xs[i];
        xs[i] = s; 
        int e = lower_bound(ALL(x), xe[i]) - x.begin();
        xm[e] = xe[i];
        xe[i] = e; 
    }
    return x.size();
}

int main(void)
{
    int N,K;
    cin >> N >> K;
    vector<ll> xs(N), xe(N);    
    vector<ll> ys(N), ye(N);    
    vector<ll> zs(N), ze(N);    

    REP(i, N){
        cin>>xs[i]>>ys[i]>>zs[i]>>xe[i]>>ye[i]>>ze[i];
    }
    map<int, ll> xm, ym, zm;
    int x = compress(xs, xe, xm);
    int y = compress(ys, ye, ym);
    int z = compress(zs, ze, zm);

    vector<vector<vector<int>>> m(x+1, vector<vector<int>>(y+1, vector<int>(z+1,0)));

    REP(i, N){
        m[xs[i]][ys[i]][zs[i]] += 1;
        m[xe[i]][ys[i]][zs[i]] -= 1;
        m[xs[i]][ye[i]][zs[i]] -= 1;
        m[xe[i]][ye[i]][zs[i]] += 1;

        m[xs[i]][ys[i]][ze[i]] -= 1;
        m[xe[i]][ys[i]][ze[i]] += 1;
        m[xs[i]][ye[i]][ze[i]] += 1;
        m[xe[i]][ye[i]][ze[i]] -= 1;
    }

    REP(i, x)REP(j, y)REP(k, z) m[i+1][j][k] += m[i][j][k];
    REP(i, x)REP(j, y)REP(k, z) m[i][j+1][k] += m[i][j][k];
    REP(i, x)REP(j, y)REP(k, z) m[i][j][k+1] += m[i][j][k];
    
    ll ans = 0;
    REP(i, x)REP(j, y)REP(k, z){
        // if(m[i][j][k]>=K) ans += (xm[xs[i]+1]-xm[xs[i]])*(ym[ys[j]+1]-ym[ys[j]])*(zm[zs[k]+1]-zm[zs[k]]);
        if(m[i][j][k]>=K) {
            ans += (xm[i+1]-xm[i])*(ym[j+1]-ym[j])*(zm[k+1]-zm[k]);
        }
    }

    pr(ans);
}