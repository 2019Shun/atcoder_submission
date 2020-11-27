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
#define fi first
#define se second
using namespace std;
template<class A>void pr(A a){cout << (a) << endl;}
template<class A,class B>void pr(A a,B b){cout << a << " "  ;pr(b);}
template<class A,class B,class C>void pr(A a,B b,C c){cout << a << " " ;pr(b,c);}
template<class A,class B,class C,class D>void pr(A a,B b,C c,D d){cout << a << " " ;pr(b,c,d);}
typedef long long ll;
typedef pair<int, int> pii;

int h,w;
int m[2000][2000];
int t[2000][2000];
int yo[2000][2000];

int solve(int x, int y){
    if(m[x][y]==0)return 0;
    int tate = 1;
    int yoko = 1;

    //Up
    if(t[x][y]){
        tate = t[x][y];
    }else{
        for (int i = x-1; i >= 0; i--)
        {
            if(m[i][y])tate++;
            else break;
        }
        //Down
        for (int i = x+1; i < h; i++)
        {
            if(m[i][y])tate++;
            else break;
        }

        t[x][y] = tate;
        for (int i = x-1; i >= 0; i--)
        {
            if(m[i][y])t[i][y] = tate;
            else break;
        }
        //Down
        for (int i = x+1; i < h; i++)
        {
            if(m[i][y])t[i][y] = tate;
            else break;
        }
    }

    if(yo[x][y]){
        yoko = yo[x][y];
    }else{
        //Left
        for (int i = y-1; i >= 0; i--)
        {
            if(m[x][i])yoko++;
            else break;
        }
        //Right
        for (int i = y+1; i < w; i++)
        {
            if(m[x][i])yoko++;
            else break;
        }

        //Left
        yo[x][y] = yoko;
        for (int i = y-1; i >= 0; i--)
        {
            if(m[x][i])yo[x][i] = yoko;
            else break;
        }
        //Right
        for (int i = y+1; i < w; i++)
        {
            if(m[x][i])yo[x][i] = yoko;
            else break;
        }
    }
    return tate + yoko -1;
}

int main(void)
{
    cin >> h >> w;
    REP(i, h){
        REP(j, w){
            char a;
            cin >> a;
            if(a == '.')m[i][j] = 1;
        }
    }

    int ans = 0;
    REP(i, h){
        REP(j, w){
            ans = max(ans, solve(i,j));
        }
    }
    pr(ans);
}