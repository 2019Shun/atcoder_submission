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
#define YES(n) cout<<((n)?"YES":"NO")<<endl
#define pb push_back
using namespace std;
template<class A>void pr(A a){cout << (a) << endl;}
template<class A,class B>void pr(A a,B b){cout << a << " "  ;pr(b);}
template<class A,class B,class C>void pr(A a,B b,C c){cout << a << " " ;pr(b,c);}
template<class A,class B,class C,class D>void pr(A a,B b,C c,D d){cout << a << " " ;pr(b,c,d);}
typedef long long ll;
typedef pair<int, int> pii;

class Vec2{
public:
    int x;int y;
    Vec2(int x=0, int y=0) : x(x), y(y){};
    Vec2 operator+(Vec2 v){
        return Vec2(x+v.x, y+v.y);
    }
    Vec2 operator-(Vec2 v){
        return Vec2(x-v.x, y-v.y);
    }
};

int main(void)
{
    int h,w,n;
    cin >> h >> w >> n;
    vector<string> m(h);
    vector<Vec2> s(n+1);
    REP(i, h){
        cin >> m[i];
        REP(j, w){
            if(m[i][j]=='S')s[0] = Vec2(i,j);
            else if('1' <= m[i][j] && m[i][j] <= '9') s[m[i][j]-'0'] = Vec2(i,j);
        }
    }

    int ans=0;
    Vec2 diff[4] = {Vec2(-1,0),Vec2(1,0),Vec2(0,-1),Vec2(0,1)};
    REP(i, n){
        queue<Vec2> q;
        q.push(s[i]);
        vector<string> _m = m;///マップ複製
        vector<vector<int>> cost(h, vector<int>(w, 0));
        while(q.size()){
            Vec2 f = q.front();q.pop();
            REP(j, 4){
                Vec2 a = f + diff[j];
                if(0 <= a.x && a.x < h && 0 <= a.y && a.y < w){
                    if(_m[a.x][a.y] == '.' || ('1' <= _m[a.x][a.y] && _m[a.x][a.y] <= '9') || (i != 0 && _m[a.x][a.y] == 'S')){
                    // if(_m[a.x][a.y] != '#'){
                        q.push(a);
                        cost[a.x][a.y] = cost[f.x][f.y]+1;
                        _m[a.x][a.y] = '#';
                    }
                    // if(a.x == s[i+1].x && a.y == s[i+1].y){
                    //     ans += cost[f.x][f.y]+1;
                    //     queue<Vec2> e;q = e;
                    //     break;
                    // }
                }
            }
        }
        ans += cost[s[i+1].x][s[i+1].y];
    }
    pr(ans);
}