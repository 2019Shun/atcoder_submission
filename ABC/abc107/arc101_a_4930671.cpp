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

int main(void)
{
    ll n,k;
    cin >> n >> k;
    vector<ll> mx, px;
    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        if(tmp >= 0) px.pb(tmp);
        else mx.pb(abs(tmp));
    }
    SORT(px);
    SORT(mx);

    vector<int> v;
    if(mx.size() >= k) v.pb(mx[k-1]);
    if(px.size() >= k) v.pb(px[k-1]);
    REP(i, k){
        int pid = i;
        int mid = k-i-2;
        if(px.size() <= pid || pid < 0) continue;
        if(mx.size() <= mid || mid < 0) continue;
        int p = px[pid];
        int m = mx[mid];
        v.pb(m > p ? m+p*2 : p+m*2);
    }
    SORT(v);
    pr(v[0]);
}