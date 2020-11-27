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
    int N,M,Q;
    cin >> N >> M >> Q;
    vector<int> a(Q), b(Q), c(Q), d(Q);
    REP(i, Q) cin >> a[i] >> b[i] >> c[i] >> d[i];
    int nm = N+M-1;
    vector<int> v(N);
    int ans = 0;
    REP(i, 1<<nm){
        if(__builtin_popcount(i) == N-1){
            if(i&1) continue;
            int tmp = 0;
            int id = 0;
            REP(j, nm){ //0だったらカウント，1だったら代入して数列を作成
                if(i&(1<<j)) v[id++] = tmp;
                else tmp++; 
            }
            v[id] = tmp;
            int tmpans = 0;
            REP(j, Q){
                if(v[b[j]-1]-v[a[j]-1]==c[j]) tmpans += d[j];
            }
            chmax(ans, tmpans);
        }
    }
    pr(ans);
}