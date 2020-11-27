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

//cost_map[vertex] pll -> <to, cost>
bool bellman_ford(ll s, vector<vector<pll>>& cost_map, vector<ll>& result){
    ll N = cost_map.size();
    vector<ll> d(N, MAXINF);
    d[s] = 0;
    REP(k, N){
        REP(i, N){
            if(d[i]==MAXINF)continue;
            for(auto&& v : cost_map[i]){
                if(d[v.fi] > d[i] + v.se){
                    d[v.fi] = d[i] + v.se;
                    if(k==N-1)
                        return false;
                }
            }
        }
    }
    result = d;
    return true;
}

int main(void)
{
    int N,M,P;
    cin >> N >> M >> P;
    vector<vector<pll>> cost(N);
    vector<vector<int>> m(N);
    REP(i, M){
        int a,b,c;
        cin >> a >> b >> c;
        a--;b--;
        cost[a].pb(pll(b, -c+P));
        m[b].pb(a);
    }

    //ゴールに到達できない頂点を削除
    // Rep(i, 1, N-1){
    //     queue<int> q;
    //     q.push(i);
    //     vector<int> ok(N, 0);
    //     while(!q.empty()){
    //         auto f = q.front();q.pop();
    //         ok[f] = 1;
    //         for(auto&& i : cost[f]){
    //             if(ok[i.fi])continue;
    //             q.push(i.fi);
    //         }
    //     }
    //     if(!ok[N-1]){
    //         cost[i].clear();
    //         break;
    //     }
    // }
    queue<int> q;
    q.push(N-1);
    vector<int> ok(N, 0);
    while(!q.empty()){
        auto f = q.front();q.pop();
        ok[f] = 1;
        for(auto&& i : m[f]){
            if(ok[i]) continue;
            q.push(i);
        }
    }
    REP(i, N){
        if(!ok[i])
            cost[i] = vector<pll>();
    }

    vector<ll> res;
    if(bellman_ford(0, cost, res)){
        if(res[N-1]>0) {
            pr(0);
        }else{
            pr(-res[N-1]);
        }
    }else{
        pr(-1);
    }
}