#include <bits/stdc++.h>
#include <vector>
#include <numeric>
#define PI 3.14159265358979323846
#define MAXINF 1e18L
#define INF 1e9L
#define EPS 1e-9
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
#define pb push_back
using namespace std;
template<class A>void pr(A a){cout << (a) << endl;}
template<class A,class B>void pr(A a,B b){cout << a << " "  ;pr(b);}
template<class A,class B,class C>void pr(A a,B b,C c){cout << a << " " ;pr(b,c);}
template<class A,class B,class C,class D>void pr(A a,B b,C c,D d){cout << a << " " ;pr(b,c,d);}
typedef long long ll;
typedef pair<int, int> pii;

int main(void)
{
    int dx[] = {0,0,-1,1};
    int dy[] = {-1,1,0,0};

    int h,w;
    cin >> h >> w;
    vector<vector<int>> d(h, vector<int>(w, -1));
    vector<pii> e;
    REP(i, h){
        REP(j, w){
            char c; cin >> c;
            if(c=='#'){
                d[i][j] = 0;
                e.pb({i,j});
            }
        }
    }
    int ans = 0;
    REP(i, e.size()){
        int x = e[i].first;
        int y = e[i].second;
        ans = max(ans, d[x][y]);
        REP(j, 4){
            int gx = x + dx[j];
            int gy = y + dy[j];
            if(gx >= 0 && gy >= 0 && gx < h && gy < w && d[gx][gy] == -1){
                d[gx][gy] = d[x][y]+1;
                e.pb({gx,gy});
            }
        }
    }
    pr(ans);
}