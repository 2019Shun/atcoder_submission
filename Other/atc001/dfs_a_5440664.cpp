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

int h,w;
int c[500][500];

int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};

bool dfs(int x, int y){
    if(c[x][y]==1) return true;
    if(c[x][y]==-1) return false;
    else c[x][y]=-1;

    bool flag=false;
    REP(i, 4){
        int nx = x+dx[i];
        int ny = y+dy[i];
        if(0<=nx&&nx<h && 0<=ny&&ny<w) 
            if(dfs(nx,ny)) flag =true;
    }
    return flag;
}

int main(void)
{
    cin >> h >> w;
    int sx,sy;
    REP(i, h){
        REP(j, w){
            char a;cin>>a;
            switch (a)
            {
            case '#':
                c[i][j] = -1;
                break;
            case 's':
                c[i][j] = 0;
                sx=i;
                sy=j;
                break;
            case 'g':
                c[i][j] = 1;
                break;
            case '.':
                c[i][j] = 0;
                break;
            }
        }
    }
    Yes(dfs(sx,sy));  
}