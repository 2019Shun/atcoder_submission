#include <bits/stdc++.h>
#include <vector>
#include <numeric>
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
    int N,M;
    cin >> N >> M;
    auto n2q = [](int n){//数字ｰ>必要な本数
        switch (n)
        {
        case 1: return 2; break;
        case 2: case 3: case 5: return 5; break;
        case 6: case 9: return 6; break;
        case 4: return 4; break;
        case 7: return 3; break;
        case 8: return 7; break;
        }
    };
    vector<int> A(M);
    vector<pii> AP;
    REP(i, M){
        int a;
        cin >> a;
        A[i] = a;
        AP.pb(pii(a, n2q(a)));
    }
    RSORT(AP);

    vector<int> dp(N+1, -INF);
    dp[0] = 0;
    REP(i, N+1){
        if(dp[i] < 0) continue;
        REP(j, M){
           if(i+AP[j].se <= N){
               chmax(dp[i+AP[j].se], dp[i] + 1);
           }
       } 
    }
    int i = N;
    while(i > 0){
        REP(j, M){
            if(i-AP[j].se >= 0 && dp[i] - dp[i-AP[j].se] == 1){
                cout << AP[j].fi;
                i -= AP[j].se;
                break;
            }
        }
    }
    cout << endl;
}