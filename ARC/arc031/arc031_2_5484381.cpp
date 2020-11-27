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

int a[10][10];
int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};

bool dfs(int x, int y, int b){
    if(a[x][y]!=0) return false;
    a[x][y]=b;
    REP(i, 4){
        int xi = x+dx[i], yi = y+dy[i];
        if(0<=xi && xi<10 && 0<=yi && yi<10) dfs(xi,yi,b);
    }
    return true;
}

int main(void)
{   
    REP(i, 10){
        REP(j, 10){
            char c;cin >>c;
            if(c=='x')a[i][j]=-1;
            else a[i][j]=0;
        }
    }

    int b = 1;
    REP(i, 10){
        REP(j, 10){
            if(dfs(i,j,b))b++;
        }
    }
    if(b==2){
        pr("YES");
        return 0;
    }
    
    // REP(i, 10){
    //     REP(j, 10){
    //         cout << a[i][j] << ' ';
    //     }    
    //     cout<<endl;
    // }

    bool flag = false;
    REP(i, 10){
        REP(j, 10){
            map<int,int> m;
            REP(k, 4){
                int x = i+dx[k], y = j+dy[k];
                if(0<=x&&x<10&&0<=y&&y<10){
                    if(a[x][y]>0)
                        m[a[x][y]]++;
                }
            }
            if(m.size()+1==b) {
                flag = true;
                break;
            }
        }
        if(flag) break;
    }
    YES(flag);
}