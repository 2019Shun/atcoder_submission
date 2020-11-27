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
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll,ll> pll;

vector<int> bfs(int n, int s, int t, vector<vector<int>>& to){
    vector<int> res(n*3, INF);
    queue<int> q;
    q.push(s);
    res[s] = 0;
    while(!q.empty()){
        int f = q.front();q.pop();
        for(auto&& c : to[f]){
            if(res[c] == INF){
                res[c] = res[f] + 1;
                q.push(c);
            }
        }
    }
    return res;
}

int main(void)
{
    int n,m;
    cin >> n >> m;
    vector<vector<int>> to(n*3);
    REP(i, m){
        int u,v;
        cin >> u >> v;
        u--;v--;
        to[u].pb(n+v);
        to[n+u].pb(2*n+v);
        to[2*n+u].pb(v);
    }
    int s,t;
    cin >> s >> t;
    s--;t--;

    auto ans = bfs(n, s, t, to);
    if(ans[t] == INF) pr(-1);
    else pr(ans[t]/3);
}