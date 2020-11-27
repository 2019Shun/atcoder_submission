#include <bits/stdc++.h>
#include <vector>
#include <numeric>
#define PI 3.14159265358979323846
#define MAXINF (1e18L)
#define INF (1e9L)
#define EPS (1e-9)
#define MOD (1e9+7)
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

int main(void)
{
    int n,m;
    cin >> n >> m;
    vector<bool> a(n+1,true);
    vector<ll> dp(n+1,0);
    REP(i, m){
        int b;
        cin >> b;
        a[b]=false;
    }

    dp[0]=1;
    Rep(i, 0, n){
        if(i + 1 <= n)
            if(a[i+1]){
                dp[i+1] += dp[i];
                dp[i+1] %= 1'000'000'007;
            }

        if(i + 2 <= n)
            if(a[i+2]){
                dp[i+2] += dp[i];
                dp[i+2] %= 1'000'000'007;
            }
    }
    // DEBUG_VEC(dp);
    pr(dp[n]);
}