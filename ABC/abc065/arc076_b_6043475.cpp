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

class union_find{
public:
    vector<int> parent;
    union_find(int n) : parent(vector<int>(n, -1)) {} //Parent is -(size of set)
    int root(int a){ return (parent[a] < 0 ? a : parent[a] = root(parent[a])); }
    int size(int a){ return -parent[root(a)]; }
    bool same(int &a, int &b){ a=root(a);b=root(b); return (a==b); }
    bool connect(int a, int b){
        if(same(a,b)) return false;
        if(size(a)<size(b)) a^=b^=a^=b;
        parent[a] += parent[b]; parent[b]=a;
        return true;
    }
};

//v -> number of vertex,
//g -> cost_map (cost, (start, target))
ll kruskal(int v, vector<pair<ll, pii>> &g){
    union_find uf(v);
    SORT(g);
    ll ans = 0;
    for(ll i = 0; i < g.size(); i++){
        if(!uf.same(g[i].second.first, g[i].second.second)){
            ans += g[i].fi;
            uf.connect(g[i].second.first, g[i].second.second);
        }
    }
    return ans;
}

int main(void)
{
    int n;
    cin >> n;
    vector<pii> x(n), y(n);
    REP(i, n){
        int xi,yi;
        cin >> xi >> yi;
        x[i] = pii(xi, i);
        y[i] = pii(yi, i);
    }

    SORT(x);
    SORT(y);

    vector<pair<ll, pii>> g;
    REP(i, n-1){
        g.pb(pair<ll, pii>(x[i+1].fi - x[i].fi, pii(x[i].se, x[i+1].se))); 
        g.pb(pair<ll, pii>(y[i+1].fi - y[i].fi, pii(y[i].se, y[i+1].se))); 
    }
    pr(kruskal(n, g));
}