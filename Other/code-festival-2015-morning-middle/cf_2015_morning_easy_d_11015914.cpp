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

string lcs(string s,string t)
{
    int n = s.size(), m = t.size();
    int i,j,dp[n+1][m+1];
    for(i=0;i<=n;i++) dp[i][0]=0;
    for(j=0;j<=m;j++) dp[0][j]=0;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
            if(s[i-1]==t[j-1]) dp[i][j]=dp[i-1][j-1]+1;
            else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }
    int l=dp[n][m]; i=n;j=m; string S;
    while(l!=0)
    {
        if(dp[i][j]==dp[i-1][j]) i--;
        else if(dp[i][j]==dp[i][j-1]) j--;
        else
        {
            S+=s[i-1];
            i--;j--;l--;
        }
    }
    reverse(S.begin(),S.end());
    return S;
}

int main(void)
{
    int N;
    cin >> N;
    string S;
    cin >> S;
    
    int ans = INF;
    Rep(i, 1, N){
        chmin(ans, (int)(N-lcs(S.substr(0, i), S.substr(i, N-i)).length()*2));
    }
    if(ans==INF)pr(N);
    else pr(ans);
}