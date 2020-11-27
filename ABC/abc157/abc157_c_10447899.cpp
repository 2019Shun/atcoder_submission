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

int s[10], c[10];

int main(void)
{
    int N,M;
    cin >> N >> M;
    int n = 1000;
    if(N == 1) n = 10;
    if(N == 2) n = 100;

    REP(i, M){
        cin >> s[i] >> c[i];
    }

    if(N==3)
    Rep(i, 100, n){
        bool f = true;
        vector<int> num(N);
        num[2] = i%10;
        num[1] = (i/10)%10;
        num[0] = (i/100)%10;
        REP(j, M){
            if(num[s[j]-1] != c[j]) f = false;
        }
        if(f){
            pr(i);
            return 0;
        }
    }
    else if(N==2)
    Rep(i, 10, n){
        bool f = true;
        vector<int> num(N);
        num[1] = i%10;
        num[0] = (i/10)%10;
        REP(j, M){
            if(num[s[j]-1] != c[j]) f = false;
        }
        if(f){
            pr(i);
            return 0;
        }
    }
    else if(N==1)
    REP(i, n){
        bool f = true;
        vector<int> num(N);
        num[0] = i%10;
        REP(j, M){
            if(num[s[j]-1] != c[j]) f = false;
        }
        if(f){
            pr(i);
            return 0;
        }
    }
    pr(-1);
}

