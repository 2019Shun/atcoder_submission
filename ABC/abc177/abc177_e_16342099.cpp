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

int count_prime(int n){
    int p = 0;
    vector<int> prime(n+1, true);
    prime[0] = prime[1] = false; 
    for(int i = 2; i <= n; i++)
        if(prime[i]) {
            p++;
            for (int j = i*2; j <= n; j += i) prime[j] = false;
        }
    return p;
}

ll gcd(ll a, ll b) {return (b==0)?a:gcd(b,a%b);}
ll lcm(ll a, ll b) {return a*(b/gcd(a, b));}

int main(void)
{
    int N;
    cin >> N;
    vector<int> A(N);
    int n = 1000005;
    vector<int> v(n);
    REP(i,N) cin >> A[i];
    REP(i,N) v[A[i]]++;

    ll g = gcd(A[0], A[1]);
    Rep(i, 1, N-1){
        g = gcd(g, A[i+1]);
    }
    
    int p = 0;
    vector<int> prime(n+1, true);
    prime[0] = prime[1] = false; 
    for(int i = 2; i <= n; i++) if(prime[i]) {
        p++;
        for (int j = i*2; j <= n; j += i) prime[j] = false;
    }

    vector<ll> ans(n);
    Rep(i, 2, n){
        if(!prime[i]) continue;
        ll t = i;
        while(t < n){
            ans[i] += v[t];
            t += i;
        }
    }

    ll m = 1;
    Rep(i, 1, n){
        chmax(m, ans[i]);
    }

    if(m == 1){
        pr("pairwise coprime");
    }else if(g == 1){
        pr("setwise coprime");
    }else{
        pr("not coprime");
    }
}