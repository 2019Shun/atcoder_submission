#include <bits/stdc++.h>
#include <vector>
#include <numeric>
#define PI 3.14159265358979323846
#define MAXINF (1e18L)
#define INF (1e9L)
#define EPS (1e-9)
#define MOD (1'000'000'007)
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

vector<vector<int>> graph;
vector<int> color;

bool dfs(int c, int p){
    color[p]=c;
    for(int cc : graph[p]){
        if(color[cc]==c) return false;
        if(color[cc]==0) if(!dfs(-c, cc)) return false;
    }    
    return true;
}

int main(void)
{
    int n,m;
    cin >> n >> m;
    graph.resize(n, vector<int>());
	color.resize(n, 0);
    REP(i, m){
        int a,b;
        cin >> a >> b;
        a--;b--;
        graph[a].pb(b);
        graph[b].pb(a);
    }

    ll ans=0;
    if(dfs(1,0)){
        ll w=0;
        REP(i, n){
            if(color[i]==1) w++;
        }
        ans = w * (n-w) - m; 
    }else{
        ans = (ll)n*(n-1)/2 - m;
    }

    pr(ans);
}