#include <bits/stdc++.h>
#define PI 3.14159265358979323846
#define MAXINF (1e18L)
#define INF (1e9L)
#define EPS (1e-9)
#define MOD ((ll)(1e9+7))
#define REP(i, n) for(int i=0;i<int(n);++i)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define REPA(i, v) for(auto&& i : v)
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
template<class T> void pr_vec(vector<T> &v, char ep=' '){int n=v.size();REP(ni,n){cout<<v[ni];if(ni!=n-1)cout<<ep;}cout<<endl;};
template<class T> inline bool chmin(T& a, T b){return a>b ? a=b, true : false;}
template<class T> inline bool chmax(T& a, T b){return a<b ? a=b, true : false;}
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll,ll> pll;

int main(void)
{
    int N;
    cin >> N;
    vector<vector<int>> E(N);
    REP(i, N-1){
        int a,b;
        cin >> a >> b;
        a--;b--;
        E[a].pb(b);
        E[b].pb(a);
    }
    vector<pii> C(N, {-1,-1});
    queue<int> q1, q2;
    q1.push(0);
    while(!q1.empty()){
        auto f = q1.front(); q1.pop();
        REPA(c, E[f]){
            if(C[c].fi==-1){
                C[c].fi = C[f].fi + 1;
                q1.push(c);
            }
        }
    }
    q2.push(N-1);
    while(!q2.empty()){
        auto f = q2.front(); q2.pop();
        REPA(c, E[f]){
            if(C[c].se==-1){
                C[c].se = C[f].se + 1;
                q2.push(c);
            }
        }
    }

    int f = 0, s = 0;
    REPA(ci,C){
        if(ci.fi <= ci.se) f++;
        else s++;
    }
    if(f>s) pr("Fennec");
    else pr("Snuke");
}