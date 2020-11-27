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

///解説放送を見て

int main(void)
{
    int x,y,z;
    cin >> x >> y >> z;
    int K;
    cin >> K;
    vector<ll> a(x), b(y), c(z);

    REP(i, x) cin >> a[i];
    REP(i, y) cin >> b[i];
    REP(i, z) cin >> c[i];

    RSORT(a);
    RSORT(b);
    RSORT(c);

    vector<ll> abc;
    REP(i, x){
        REP(j, y){
            if((i+1)*(j+1) > K) break;
            REP(k, z){
                if((i+1)*(j+1)*(k+1) > K) break;
                abc.pb(a[i] + b[j] + c[k]);
            }
        }
    }

    RSORT(abc);
    REP(i, K){
        pr(abc[i]);
    }
}