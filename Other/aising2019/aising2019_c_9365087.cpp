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

bool ok[410][410];

int main(void)
{
    int H, W;
    cin >> H >> W;
    vector<string> S(H);
    for (int i = 0; i < H; i++) {
        cin >> S[i];
    }
    
    int dx[4]={-1,1,0,0}, dy[4]={0,0,-1,1};

    ll ans = 0;
    REP(i, H)REP(j, W){
        if(S[i][j] != '#') continue;
        if(ok[i][j]) continue;

        queue<pii> q;
        q.push(pii(i,j));

        ll b = 0;
        ll w = 0;

        while(!q.empty()){
            auto f = q.front();q.pop();
            if(ok[f.fi][f.se]) continue;
            ok[f.fi][f.se] = true;

            if(S[f.fi][f.se] == '#') b++;
            else w++;

            for (size_t i = 0; i < 4; i++)
            {
                pii d(f.fi + dx[i], f.se + dy[i]);
                if(0<= d.fi && d.fi < H && 0 <= d.se && d.se < W){
                    if(ok[d.fi][d.se]) continue;
                    if(S[f.fi][f.se] != S[d.fi][d.se]){
                        q.push(d);
                    }
                }
            }
        }

        ans += b*w;
    }
    pr(ans);
}

// #include <bits/stdc++.h>
// #define PI 3.14159265358979323846
// #define MAXINF (1e18L)
// #define INF (1e9L)
// #define EPS (1e-9)
// #define MOD ((ll)(1e9+7))
// #define REP(i, n) for(int i=0;i<int(n);++i)
// #define Rep(i,sta,n) for(int i=sta;i<n;i++)
// #define RREP(i, n) for(int i=int(n)-1;i>=0;--i)
// #define ALL(v) v.begin(),v.end()
// #define FIND(v,x) (binary_search(ALL(v),(x)))
// #define SORT(v) sort(ALL(v))
// #define RSORT(v) sort(ALL(v));reverse(ALL(v))
// #define DEBUG(x) cerr<<#x<<": "<<x<<endl;
// #define DEBUG_VEC(v) cerr<<#v<<":";for(int i=0;i<v.size();i++) cerr<<" "<<v[i]; cerr<<endl
// #define Yes(n) cout<<((n)?"Yes":"No")<<endl
// #define YES(n) cout<<((n)?"YES":"NO")<<endl
// #define pb push_back
// #define fi first
// #define se second
// using namespace std;
// template<class A>void pr(A a){cout << (a) << endl;}
// template<class A,class B>void pr(A a,B b){cout << a << " "  ;pr(b);}
// template<class A,class B,class C>void pr(A a,B b,C c){cout << a << " " ;pr(b,c);}
// template<class A,class B,class C,class D>void pr(A a,B b,C c,D d){cout << a << " " ;pr(b,c,d);}
// template<class T> inline bool chmin(T& a, T b){return a>b ? a=b, true : false;}
// template<class T> inline bool chmax(T& a, T b){return a<b ? a=b, true : false;}
// typedef long long ll;
// typedef pair<int, int> pii;
// typedef pair<ll,ll> pll;

// ll ans;
// int H,W;

// void dfs(int h, int w, vector<vector<bool>> &ok, vector<string> &s){
//     ok[h][w] = true;
//     int dx[4]={-1,1,0,0}, dy[4]={0,0,-1,1};
//     for (size_t i = 0; i < 4; i++)
//     {
//         int dh = h + dx[i];        
//         int dw = w + dy[i];        
//         if(0<= dh && dh < H && 0 <= dw && dw <= W){
//             if(ok[dh][dw]) continue;
//             if(s[h][w] == '#' && s[dh][dw] == '.'){
//                 ans++;
//                 dfs(dh, dw, ok, s);
//             }else if(s[h][w] == '.' && s[dh][dw] == '#'){
//                 dfs(dh, dw, ok, s);
//             }
//         }
//     }
    
// }

// int main(void)
// {
//     cin >> H >> W;
//     vector<string> S(H);
//     for (int i = 0; i < H; i++) {
//         cin >> S[i];
//     }
//     vector<pii> c1;
//     REP(i, H) REP(j, W){
//         if(S[i][j]=='#') c1.pb(pii(i,j));
//     }

//     for(auto&& b : c1){
//         vector<vector<bool>> ok(H, vector<bool>(W, false));
//         dfs(b.fi, b.se, ok, S);
//     }

//     pr(ans);
// }