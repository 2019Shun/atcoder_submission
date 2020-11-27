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
    double Ax,Ay,Bx,By;
    cin >> Ax >> Ay >> Bx >> By;
    int N;
    cin >> N;
    vector<pair<double, double>> xy(N);
    REP(i, N) {
        cin >> xy[i].fi >> xy[i].se;
    }
    int it = 0;
    REP(i, N){
        double v0x = Bx - Ax;
        double v0y = By - Ay;
        double v1x = xy[i].fi - Ax;
        double v1y = xy[i].se - Ay;
        double v2x = xy[(i!=N-1)?(i+1):0].fi - Ax;
        double v2y = xy[(i!=N-1)?(i+1):0].se - Ay;
        double s1 = (v0x * v1y - v1x*v0y) / 2.0;
        double s2 = (v0x * v2y - v2x*v0y) / 2.0;
        v0x = xy[(i!=N-1)?(i+1):0].fi - xy[i].fi;
        v0y = xy[(i!=N-1)?(i+1):0].se - xy[i].se;
        v1x= Ax - xy[i].fi;
        v1y = Ay - xy[i].se;
        v2x = Bx - xy[i].fi;
        v2y = By - xy[i].se;
        double s3 = (v0x * v1y - v1x*v0y) / 2.0;
        double s4 = (v0x * v2y - v2x*v0y) / 2.0;
        if((s1*s2 <= 0)&&(s3*s4 <= 0)){
            it++;
        }
    }
    pr(it/2+1);
}
