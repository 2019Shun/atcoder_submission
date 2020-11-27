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

int f(ll x){
    if(x==0) return 0;
    int ans = 1;
    int p = __builtin_popcount(x);
    while((x%p)){
        x = (x%p);
        p = __builtin_popcount(x);
        ans++;
    }
    return ans;
}


int main(void)
{
    int N;
    cin >> N;
    string X;
    cin >> X;
    reverse(ALL(X));
    
    ll n = 0;
    REP(i, N) if(X[i]=='1') n++;

    vector<ll> x0(N), x1(N);
    x0[0] = x1[0] = 1;
    Rep(i, 1, N){
        x0[i] = (x0[i-1]*2) % (n+1);
        if(n!=1) x1[i] = (x1[i-1]*2) % (n-1);
    }

    ll X0 = 0, X1 = 0;
    REP(i, N){
        if(X[i]=='1'){
            (X0 += x0[i]) %= (n+1);
            if(n!=1) (X1 += x1[i]) %= (n-1);
        }
    }

    vector<int> ans;
    REP(i, N){
        if(X[i]=='0'){
            ll tmp = X0;
            (tmp += x0[i]) %= (n+1);
            ans.pb(f(tmp));
        }else{
            if(n==1){
                ans.pb(-1);
                continue;
            }
            ll tmp = X1;
            ((tmp -= x1[i]) += (n-1)) %= (n-1);
            ans.pb(f(tmp));
        }
    }
    reverse(ALL(ans));
    REP(i, N){
        pr(ans[i]+1);
    }
}