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
typedef pair<ll,pii> plp;

int main(void)
{
    int H,W;
    ll T;
    cin >> H >> W >> T;
    vector<string> S(H);
    REP(i,H) cin >> S[i];
    pii s, g;
    REP(i, H)REP(j, W){
        if(S[i][j]=='S') s={i,j};
        if(S[i][j]=='G') g={i,j};
    }

    ll l = 1, r = T+1;
    while(r-l>1){
        ll mid = (l+r)/2;
        priority_queue<plp> q;
        q.push(plp(0, s));
        vector<vector<ll>> ok(H, vector<ll>(W, MAXINF));
        ok[s.fi][s.se] = 0;
        int dx[4]={-1,1,0,0}, dy[4]={0,0,-1,1};
        while(!q.empty()){
            auto f = q.top();q.pop();
            REP(i, 4){
                int x = f.se.fi + dx[i];
                int y = f.se.se + dy[i];
                if(!(0<=x&&x<H&&0<=y&&y<W)) continue;

                if(S[x][y]=='#') {
                    if(chmin(ok[x][y], (-f.fi)+mid)) q.push(plp(-ok[x][y], {x,y}));
                }else {
                    if(chmin(ok[x][y], (-f.fi)+1)) q.push(plp(-ok[x][y], {x,y}));
                }
            }
        }
        if(ok[g.fi][g.se] <= T) l = mid;
        else r = mid;
    }

    pr(l);
}