#include <bits/stdc++.h>
#include <vector>
#include <numeric>
#define PI 3.14159265358979323846
#define MAXINF 1e18L
#define INF 1e9L
#define EPS 1e-9
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
#define pb push_back
using namespace std;
template<class A>void pr(A a){cout << (a) << endl;}
template<class A,class B>void pr(A a,B b){cout << a << " "  ;pr(b);}
template<class A,class B,class C>void pr(A a,B b,C c){cout << a << " " ;pr(b,c);}
template<class A,class B,class C,class D>void pr(A a,B b,C c,D d){cout << a << " " ;pr(b,c,d);}
typedef long long ll;
typedef pair<int, int> pii;

ll gcd(ll a, ll b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int main(void)
{
    int n;
    cin >> n;
    vector<ll> a(n);
    vector<ll> l(n);
    vector<ll> r(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if(i==0) l[i] = a[i];
        if(i>0) l[i] = gcd(l[i-1], a[i]);
    }
    RREP(i, n){
        if(i==n-1) r[i] = a[i];
        if(i<n-1) r[i] = gcd(a[i], r[i+1]);
    }

    ll ans = 0;
    ans = max(l[n-2], r[1]);
    Rep(i, 1, n-1){
        ans = max(ans, gcd(l[i-1], r[i+1]));
    }
    pr(ans);
}