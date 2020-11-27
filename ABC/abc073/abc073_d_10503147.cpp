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
                    if(k==N-1) return false;
                }
            }
        }
    }
    result = d;
    return true;
}

int result[1000][1000];
void warshall_floyd(vector<vector<pii>>& cost_map){
    int n = cost_map.size();
    //配列の準備
    REP(i, n)REP(j, n) result[i][j] = INF;
    REP(i, n) result[i][i] = 0;
    REP(i, n) for(auto&& cost : cost_map[i]) result[i][cost.first] = cost.second;
    //ワーシャルフロイド法による最短経路探索
    REP(i, n)REP(j, n)REP(k, n) chmin(result[j][k], result[j][i] + result[i][k]);
}

int main(void)
{
    int N,M,R;
    cin >> N >> M >> R;
    vector<int> r(R);
    for (int i = 0; i < R; i++) {
        cin >> r[i];
        r[i]--;
    }
    SORT(r);
    vector<vector<pii>> cost_map(N);
    REP(i, M){
        int A,B,C;
        cin >> A >> B >> C;
        A--;B--;
        cost_map[A].emplace_back(B, C);
        cost_map[B].emplace_back(A, C);
    }

    warshall_floyd(cost_map);

    int ans = INF;
    do{
        int tmp_ans = 0;
        REP(i, R-1){
            tmp_ans += result[r[i]][r[i+1]];
        }
        chmin(ans, tmp_ans);
    }while(next_permutation(ALL(r)));

    pr(ans);
}