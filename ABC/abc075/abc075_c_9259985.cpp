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

void dfs(vector<vector<int>> &graph, vector<int> &ok, int p){
    ok[p] = 1;
    for(auto&& c : graph[p]){
        if(ok[c] == 1) continue;
        dfs(graph, ok, c);
    }
}

int main(void)
{
    int N,M;
    cin >> N >> M;
    vector<pii> edge;
    REP(i, M){
        int a,b;
        cin >> a >> b;
        a--;b--;
        edge.pb(pii(a,b));
    }

    vector<int> ok(N, 0);

    int ans = 0;
    REP(i, M){
        vector<vector<int>> graph(N, vector<int>());
        REP(j, M){
            if(i == j) continue;
            int a = edge[j].fi;
            int b = edge[j].se;
            graph[b].pb(a);
            graph[a].pb(b);

        }
        
        REP(j, N) ok[j] = 0;

        dfs(graph, ok, 0);

        REP(j, N) if(ok[j] == 0){
            ans++;
            break;
        }
    }

    pr(ans);
}