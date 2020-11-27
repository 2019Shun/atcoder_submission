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
    int n;
    cin >> n;
    vector<pair<pii, int>> v(n);
    REP(i, n){
        cin >> v[i].fi.fi >> v[i].fi.se >> v[i].se;
    }

    auto f = [](pair<pii, int> p, int cx, int cy){
        if(p.se == 0) return 0;
        return p.se + abs(p.fi.fi - cx) + abs(p.fi.se - cy);
    };
    auto f2 = [](int H, int x, int y, int cx, int cy){
        return max(H - abs(x-cx) - abs(y - cy), 0);
    };

    REP(i, 101){
        REP(j, 101){
            // vector<int> h(n);
            // REP(k, n){
            //     h[k] = f(v[k], i, j);
            // }
            // SORT(h);
            // int it = 0;
            // REP(k,n) if(h[k] != 0){
            //     it = k;
            //     break;
            // }
            // if(h[it] == h[n-1]){
            //     pr(i,j,h[it]);
            //     return 0;
            // }
            int h = 0;
            REP(k, n){
                h = f(v[k], i, j);
                if(h != 0) break;
            }
            bool flag = true;
            REP(k, n){
                if(v[k].se != f2(h, v[k].fi.fi, v[k].fi.se, i, j)){
                    flag = false;
                    break;
                }
            }
            if(flag){
                pr(i, j, h);
            }
        }
    }
}