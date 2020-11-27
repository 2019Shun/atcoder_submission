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


int main(void)
{
    int H,W;
    cin >> H >> W;
    vector<string> S(H);
    REP(i, H) cin >> S[i];
    vector<pii> start;
    REP(i, H)REP(j, W){
        if(S[i][j] == '.'){
            start.pb(pii(i,j));
        }
    }
    int n = start.size();

    int ans = 0;
    REP(i, n-1){
        Rep(j, i+1, n){
            auto s = start[i];
            auto g = start[j];

            queue<pii> q;
            q.push(s);
            vector<vector<int>> ok(H, vector<int>(W, -1));
            ok[s.fi][s.se] = 0;


            while (!q.empty())
            {
                auto f = q.front();q.pop();
                int dx[4]={-1,1,0,0}, dy[4]={0,0,-1,1};
                for (size_t k = 0; k < 4; k++)
                {
                    int dh = f.fi + dx[k];
                    int dw = f.se + dy[k];
                    if(0 <= dh && dh < H && 0 <= dw && dw < W){
                        if(ok[dh][dw] == -1 && S[dh][dw] == '.'){
                            ok[dh][dw] = ok[f.fi][f.se] + 1;
                            q.push(pii(dh, dw));
                        }
                    }
                }
                    
            }
            ans = max(ans, ok[g.fi][g.se]);
        }
    }
    pr(ans);
}