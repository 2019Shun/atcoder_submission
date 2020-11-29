#include <bits/stdc++.h>
#define PI 3.14159265358979323846
#define MAXINF (1e18L)
#define INF (1e9L)
#define EPS (1e-9)
#define MOD ((ll)(1e9+7))
#define REP(i, n) for(int i=0;i<int(n);++i)
#define REPA(x, v) for(auto&& x:v)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define RREP(i, n) for(int i=int(n)-1;i>=0;--i)
#define ALL(v) v.begin(),v.end()
#define FIND(v,x) (binary_search(ALL(v),(x)))
#define SORT(v) sort(ALL(v))
#define RSORT(v) sort(v.rbegin(),v.rend())
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

// ダイクストラ法による単一始点最短経路問題
// 計算量：O((E+V)logV)
// cost_map[vertex] pll -> <to, cost>
// 到達不可能な点についてはMAXINFであることに注意
vector<ll> dijkstra(ll s, vector<vector<pll>>& cost_map){
    vector<ll> d(cost_map.size(), MAXINF);
    priority_queue<pll, vector<pll>, greater<pll>> q;
    q.push(pll(0, s));
    d[s] = 0;
    while(!q.empty()){
        pll f = q.top();q.pop();
        if(d[f.se] < f.fi) continue;
        for(auto&& v : cost_map[f.se]){
            ll value = f.fi + v.se;
            if(value < d[v.fi]) q.push(pll(d[v.fi] = f.fi + v.se, v.fi));
        }
    }
    return d;
}

int main(void)
{
    int a,b,x,y;
    cin >> a >> b >> x >> y;
    a--;b--;
    vector<vector<pll>> cost(200);
    REP(i, 100){
        if(i!=0) cost[i].emplace_back(i-1, y);
        if(i!=99) cost[i].emplace_back(i+1, y);
        if(i!=0) cost[i+100].emplace_back(i-1+100, y);
        if(i!=99) cost[i+100].emplace_back(i+1+100, y);

        cost[i].emplace_back(i+100, x);
        cost[i+100].emplace_back(i, x);

        if(i!=0) cost[i].emplace_back(i-1+100, x);
        if(i!=99) cost[i+100].emplace_back(i+1, x);
    }

    auto ans = dijkstra(a, cost);
    pr(ans[b+100]);
}