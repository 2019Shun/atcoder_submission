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

//https://atcoder.jp/contests/agc039/tasks/agc039_a
int main(void)
{
    string S;
    cin >> S;
    ll K;
    cin >> K;
    
    ll n = S.length();

    string tmp = S;
    SORT(tmp);
    if(tmp.front() == tmp.back()) {
        pr((n*K)/2);
        return 0;
    }

    ll ans = 0;
    if(S[0] != S[n-1]){
        Rep(i, 0, n-1){
            if(S[i] == S[i+1]){
                S[i+1] = '#';
                ans++;
            }
        }
        pr(ans*K);
    }else{
        ll a = 1, b = 1;
        REP(i, n){
            if(S[i] == S[i+1]) a++;
            else break;
        }
        RREP(i, n){
            if(S[i] == S[i-1]) b++;
            else break;
        }


        Rep(i, 0, n-1){
            if(S[i] == S[i+1]){
                S[i+1] = '#';
                ans++;
            }
        }

        pr(ans*K - (a/2 + b/2)*(K-1) + ((a+b)/2)*(K-1));
    }
}