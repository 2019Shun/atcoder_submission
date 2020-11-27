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

std::ostream &operator<<(std::ostream &dest, __int128_t value) {
  std::ostream::sentry s(dest);
  if (s) {
    __uint128_t tmp = value < 0 ? -value : value;
    char buffer[128];
    char *d = std::end(buffer);
    do {
      --d;
      *d = "0123456789"[tmp % 10];
      tmp /= 10;
    } while (tmp != 0);
    if (value < 0) {
      --d;
      *d = '-';
    }
    int len = std::end(buffer) - d;
    if (dest.rdbuf()->sputn(d, len) != len) {
      dest.setstate(std::ios_base::badbit);
    }
  }
  return dest;
}

struct BIT{
    vector<ll> bit; //1-indexed
    int n;
    BIT(int n) : n(n), bit(vector<ll>(n+1, 0)) {}
    ll sum(int i){
        ll s = 0;
        while(i > 0){
            s += bit[i];
            i -= i & -i;
        }
        return s;
    }
    void add(int i, int x){
        while(i <= n){
            bit[i] += (ll)x;
            i += i & -i;
        }
    }
};

int main(void)
{
    int n,k;
    cin >> n>>k;
    BIT bit(n);
    vector<int> a(n), b(n);
    REP(i, n){
        cin >> a[i];
    }
    b = a;
    SORT(b);
    map<int, int> m;
    REP(i, n){
        m[b[i]] = i+1;
    }
    ll ans = 0;
    REP(i,n){
        ans += i - bit.sum(m[a[i]]);
        bit.add(m[a[i]], 1);
    }

    BIT bit2(2*n);
    vector<int> a2(2*n), b2(2*n);
    REP(i, 2*n){
        a2[i] = a[i%n];
    }
    b2 = a2;
    SORT(b2);
    map<int, int> m2;
    REP(i, 2*n){
        m2[b2[i]] = i+1;
    }
    ll ans2 = 0;
    REP(i,2*n){
        ans2 += i - bit2.sum(m2[a2[i]]);
        bit2.add(m2[a2[i]], 1);
    }


    if(k>2){
        ans2 -= ans*2;
        (ans2 *= ((((__int128_t)k)*(k-1))/2)%MOD) %= MOD;
        (ans *= k) %= MOD;
        pr((ans + ans2)%MOD);
    }else if(k==2)
        pr(ans2%MOD);
    else{
        (ans *= k) %= MOD;
        pr(ans);
    }
    
    // __int128 l = k;
    // // (ans *= (((((l-1)*(l))/2)%MOD)+l)) %= MOD;
    // __int128 sowa = ((1+(l-1)) * ((l-1)/2.0));
    // (ans *= sowa) %= MOD;
    // pr(ans);
}