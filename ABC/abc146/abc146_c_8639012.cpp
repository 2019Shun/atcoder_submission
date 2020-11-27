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

struct IOSetup {
  IOSetup() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    cerr << fixed << setprecision(10);
  }
} iosetup;

ll A, B, X;

bool is_product_overflow(long a, long b) {
	long prod = a * b;
	return (prod / b != a);
}

ll f(ll n){
    auto func = [](ll nn){
        int ans = 0;
        while(nn != 0){
            nn /= 10;
            ans++;
        }
        return ans;
    };
    if(is_product_overflow(A, n)){
        return X+1;
    }
    if(is_product_overflow(B, (ll)func(n))){
        return X+1;
    }
    return A * n + B * (ll)func(n);
}

int main(void)
{
    cin >> A >> B;
    cin >> X;

    ll lb = 0, ub = 1000000001;
    while(ub - lb > 1){
        ll mid = (ub + lb) / 2;
        // if(f(mid) <= X){
        //     lb = mid;
        // }else{
        //     ub = mid;
        // }
        (A * mid + B * to_string(mid).length() <= X ? lb : ub) = mid;
    }
    pr(lb);
}