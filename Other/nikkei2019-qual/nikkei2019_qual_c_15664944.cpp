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

typedef pair<pll,int> ppi;

int main(void)
{
    int N;
    cin >> N;
    vector<ll> A(N), B(N);
    REP(i, N) cin >> A[i] >> B[i];

    vector<ppi> ta(N), ao(N);
    REP(i, N){
        ta[i] = {{A[i], B[i]}, i};
        ao[i] = {{A[i], B[i]}, i};
    }

    auto f1 = [](ppi a, ppi b){
        ll da = a.fi.fi + a.fi.se;
        ll db = b.fi.fi + b.fi.se;
        if(da > db) return true;
        else if(da < db) return false;
        else{
            if(a.fi.fi > b.fi.fi) return true;
            else return false;
        }
    };
    auto f2 = [](ppi a, ppi b){
        ll da = a.fi.se + a.fi.fi;
        ll db = b.fi.se + b.fi.fi;
        if(da > db) return true;
        else if(da < db) return false;
        else{
            if(a.fi.se > b.fi.se) return true;
            else return false;
        }
    };

    sort(ALL(ta), f1);
    sort(ALL(ao), f2);

    ll t = 0, a = 0;
    int tid = 0, aid = 0;
    vector<bool> ok(N);
    REP(i, N){
        if(i&1){
            while(ok[ao[aid++].se]){}
            a += B[ao[aid-1].se];
            ok[ao[aid-1].se] = true;
        }else{
            while(ok[ta[tid++].se]){}
            t += A[ta[tid-1].se];
            ok[ta[tid-1].se] = true; 
        }
    }
    pr(t-a);
}