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
    int x;
    int y;
    int v;
    Vec2(int x=0, int y=0, int v=0) : x(x), y(y), v(v) {};

    Vec2 operator+(Vec2 value){
        return Vec2(x+value.x, y+value.y, v+value.v);
    }
    Vec2 operator-(Vec2 value){
        return Vec2(x-value.x, y-value.y, v-value.v);
    }
};

int main(void)
{
    int r,c;
    cin >> r >> c;
    Vec2 s, g;
    cin >> s.x >> s.y;
    cin >> g.x >> g.y;
    s.x--;s.y--;g.x--;g.y--;
    string m[50];
    REP(i, r){
        cin >> m[i];
    }
    vector<vector<int>> v(r, vector<int>(c,0));
    
    queue<Vec2> q;
    q.push(s);
    Vec2 diff[4] = {Vec2(-1,0),Vec2(1,0),Vec2(0,-1),Vec2(0,1)};
    while(q.size()){
        Vec2 f = q.front();q.pop();
        v[f.x][f.y] = f.v;
        REP(i, 4){
            Vec2 a = f + diff[i];
            a.v++;
            if(0 <= a.x && a.x < r && 0 <= a.y && a.y < c && m[a.x][a.y]=='.'){
                m[a.x][a.y]='#';
                q.push(a);
            }
        }
    }
    pr(v[g.x][g.y]);
}