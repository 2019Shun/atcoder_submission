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
    string S;
    cin >> S;
    int n = S.size();

    vector<vector<int>> rl(n, vector<int>(2, 0));

    for (int i = n-2; i >= 0; i--) {
        if(S[i] == 'L' && S[i+1] == 'R') continue;
        if(S[i] == 'L' && S[i+1] == 'L') continue;

        if(S[i] == 'R' && S[i+1] == 'L'){
            rl[i][0] = 1;
        }else{
            rl[i][0] = rl[i+1][0]+1;
        }
    }
    for (int i = 1; i < n; i++) {
        if(S[i] == 'R' && S[i-1] == 'L') continue;
        if(S[i] == 'R' && S[i-1] == 'R') continue;

        if(S[i] == 'L' && S[i-1] == 'R'){
            rl[i][1] = 1;
        }else{
            rl[i][1] = rl[i-1][1]+1;
        }
    }

    vector<int> ans(n, 0);
    REP(i, n){
        if(S[i]=='R'){
            if(rl[i][0]&1){ //奇数
                ans[i+rl[i][0]-1]++;
            }else{
                ans[i+rl[i][0]]++;
            }
        }else{
            if(rl[i][1]&1){ //奇数
                ans[i-rl[i][1]+1]++;
            }else{
                ans[i-rl[i][1]]++;
            }
        }
    }

    REP(i, n){
        pr(ans[i]);
    }
}