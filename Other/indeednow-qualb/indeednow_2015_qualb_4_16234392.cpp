#include <bits/stdc++.h>
#define PI 3.14159265358979323846
#define MAXINF (1e18L)
#define INF (1e9L)
#define EPS (1e-9)
#define MOD ((ll)(1e9+7))
#define REP(i, n) for(int i=0;i<int(n);++i)
#define REPA(x, v) for(auto&& x:v)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define RREP(i, n) for(int i=int(n)-1;i>=0;--i)
#define ALL(v) v.begin(),v.end()
#define FIND(v,x) (binary_search(ALL(v),(x)))
#define SORT(v) sort(ALL(v))
#define RSORT(v) sort(v.rbegin(),v.rend())
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
    int N,C;
    cin >> N >> C;
    vector<int> a(N);
    REP(i,N) cin >> a[i];
    
    vector<vector<int>> p(C);
    vector<ll> ans(C);

    REP(i, N){
        // ans[a[i]-1] += (ll)(i+1)*(N-i);
        p[a[i]-1].pb(i);
    }

    REP(i, C){
        p[i].insert(p[i].begin(), -1);
        p[i].pb(N);
        int n = p[i].size();
        // if(n<=1) continue;
        // REP(j, n-1){
        //     if(j==0) ans[i] -= (p[i][j]+1)*(N-p[i][j+1]);
        //     else ans[i] -= (p[i][j]-p[i][j-1]+2)*(N-p[i][j+1]);
        //     // ans[i] -= (p[i][j]+1)*(N-p[i][j+1]);
        // }
        ans[i] = ((ll)(N+1)*N)/2;
        REP(j, n-1){
            ll len = p[i][j+1]-p[i][j]-1;
            ans[i] -= len*(len+1)/2;
        }
    }

    REP(i, C){
        pr(ans[i]);
    }
}