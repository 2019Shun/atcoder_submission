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

int main(void)
{
    int H,W;
    cin >> H >> W;
    vector<string> a(H);
    REP(i,H) cin >> a[i];
    
    pii s, g;
    vector<vector<pii>> t(26);
    REP(i, H)REP(j, W){
        if(a[i][j] == 'S') {s = {i,j}; continue;}
        if(a[i][j] == 'G') {g = {i,j}; continue;}
        if(a[i][j] == '.' || a[i][j] == '#') continue;
        t[a[i][j]-'a'].pb({i,j});
    }

    vector<vector<int>> cost(H, vector<int>(W, INF));
    vector<int> cost_tl(26, INF);
    cost[s.fi][s.se] = 0;
    deque<pii> q;
    q.push_back(s);
    while(!q.empty()){
        auto f = q.front();q.pop_front();

        // 超頂点から戻す
        if(f.fi == -1){
            REPA(x, t[f.se]){
                if(cost[x.fi][x.se] > cost_tl[f.se]){
                    cost[x.fi][x.se] = cost_tl[f.se];
                    q.push_front(x);
                }
            }
            continue;
        }
        // テレポートの処理
        if(islower(a[f.fi][f.se])){
            if(cost_tl[a[f.fi][f.se]-'a'] > cost[f.fi][f.se]+1){
                cost_tl[a[f.fi][f.se]-'a'] = cost[f.fi][f.se] + 1;
                q.push_back({-1, (a[f.fi][f.se]-'a')});
            }
        }
        // 上下左右への移動の処理
        REP(i, 4){
            int dx[4]={-1,1,0,0}, dy[4]={0,0,-1,1};
            int x = f.fi + dx[i];
            int y = f.se + dy[i];
            if(0<=x&&x<H&&0<=y&&y<W&&a[x][y]!='#'){
                if(cost[x][y] > (cost[f.fi][f.se] + 1)){
                    cost[x][y] = cost[f.fi][f.se] + 1;
                    q.push_back({x,y});
                }
            }
        }
    }
    if(cost[g.fi][g.se] == INF) pr(-1);
    else pr(cost[g.fi][g.se]);
}