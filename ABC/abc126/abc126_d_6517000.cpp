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

vector<vector<pll>> m;
vector<int> ans;
int N;

void dfs(int from, int to, ll dist){
    if((dist & 1) == 0) ans[to] = 0;
    for(auto i : m[to]){
        if(i.fi != from) dfs(to, i.fi, dist + i.se);
    }
}

int main(void)
{
    cin >> N;
    m.assign(N, vector<pll>());
    REP(i, N-1){
        int f,t,w;
        cin >> f >> t >> w;
        f--;t--;
        m[f].pb(pll(t,w));
        m[t].pb(pll(f,w));
    }

    ans.assign(N, 1);
    // queue<pll> q;
    // q.push(pll(0,0));
    // while(!q.empty()){
    //     auto f = q.front();q.pop();
    //     if((f.se & 1) == 0)ans[f.fi] = 0;
    //     for(auto i : m[f.fi]){
    //         if(ans[i.fi] == 0) continue;
    //         q.push(pll(i.fi, f.se + i.se));
    //     }
    // }

    dfs(-1, 0, 0);

    REP(i, N){
        pr(ans[i]);
    }
}