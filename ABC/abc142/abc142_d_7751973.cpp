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

map<ll, ll> prime_factor(ll n){
    map<ll, ll> res;
    for(ll i = 2; i <= n; i++)
        while (n % i == 0){
            res[i]++;
            n /= i;
        }
    return res;
}

bool is_prime(ll n){
    for (ll i = 2; i * i <= n; i++) {
        if(n % i == 0) return false;
    }
    return true;
}

int main(void)
{
    ll A,B;
    cin >> A >> B;
    // auto a = prime_factor(A);
    // auto b = prime_factor(B);

    set<ll> a;
    for (ll i = 1; i*i <= A; i++) {
        if(A%i==0) {
            a.insert(i);
            if(i*i != A) a.insert(A/i); //Nが平方数である時の対策
        }
    }

    set<ll> b;
    for (ll i = 1; i*i <= B; i++) {
        if(B%i==0) {
            b.insert(i);
            if(i*i != B) b.insert(B/i); //Nが平方数である時の対策
        }
    }


    int ans = 0;
    for(auto &&ai : a){
        if(b.count(ai) > 0){
            if(is_prime(ai)) ans++;
        }
    }
    pr(ans);
}