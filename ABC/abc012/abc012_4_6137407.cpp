#include <bits/stdc++.h>
#include <vector>
#include <numeric>
#define PI 3.14159265358979323846
#define MAXINF (1e18L)
#define INF (1e9L)
#define EPS (1e-9)
#define MOD (1e9+7)
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
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll,ll> pll;

int main(void)
{
    int n,m;
    cin >> n >> m;
    auto d = vector<vector<int>>(n, vector<int>(n, INF));
    REP(i, m){
        int a,b,t;
        cin >> a >> b >> t;
        a--;b--;
        d[a][b] = t;
        d[b][a] = t;
    }

    REP(i, n){
        d[i][i] = 0;
    }

    REP(i, n){ 
        REP(j, n){
            REP(k, n){
                d[j][k] = min(d[j][k], d[j][i] + d[i][k]);
            }
        }
    }

    vector<int> ans;
    REP(i, n){
        int a=0;
        REP(j, n){
            // cout << d[i][j] << " ";
            a = max(a, d[i][j]);
        }
        // cout << endl;
        ans.pb(a);
    }
    SORT(ans);
    pr(ans[0]);
}