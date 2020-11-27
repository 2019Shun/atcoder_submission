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
    int H,W,K;
    cin >> H >> W >> K;
    vector<string> s(H);
    for (int i = 0; i < H; i++) {
        cin >> s[i];
    }
    vector<vector<int>> ans(H, vector<int>(W));

    int prev_h = 0, now_h = 0;
    int id = 1;
    while(now_h < H){
        //Hの探索
        int n = 0;
        while(n == 0){//空白行->いちご有り
            REP(i, W){
                if(s[now_h][i] == '#') n++;
            }
            now_h++;
        }

        int t_n = 0;
        while(t_n == 0){//空白行
            if(now_h >= H) break;
            REP(i, W){
                if(s[now_h][i] == '#') t_n++;
            }
            if(t_n == 0) now_h++;
        }
        
        //Wの探索
        int prev_w = 0;
        int now_w = 0;
        while(now_w < W){
            n = 0;
            while (n == 0)
            {
                Rep(i, prev_h, now_h){
                    if(s[i][now_w] == '#') n++;
                }
                now_w++;
            }
            t_n = 0;
            while(t_n == 0){//空白行
                if(now_w >= W) break;
                Rep(i, prev_h, now_h){
                    if(s[i][now_w] == '#') t_n++;
                }
                if(t_n == 0) now_w++;
            }

            //ansに答えを入れる
            Rep(i, prev_h, now_h) Rep(j, prev_w, now_w){
                ans[i][j] = id;
            }
            id++;
            prev_w = now_w;
        }
        prev_h = now_h;
    }

    REP(i, H){
        REP(j, W){
            cout << ans[i][j] << ' ';
        }
        cout << endl;
    }
}