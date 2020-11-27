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

double calc(int w, int s){
    return 100 * s / double(w + s);
}

int main(void)
{
    int A, B, C, D, E, F;
    cin >> A >> B >> C >> D >> E >> F;
    A *= 100;
    B *= 100;
    vector<int> ab(F*F, 0);
    for (int i = 0; i < F; i++) {
        for(int j = 0; j < F; j++){
            int a = A*i + B*j;
            if(a <= F){
                ab[i * F + j] = a;
            }else{
                continue;
            }
        }
    }
    vector<int> cd(F*F, 0);
    for (int i = 0; i < F; i++) {
        for(int j = 0; j < F; j++){
            int a = C*i + D*j;
            if(a <= F){
                cd[i * F + j] = a;
            }else{
                continue;
            }
        }
    }

    SORT(ab);
    SORT(cd);
    ab.erase(unique(ALL(ab)), ab.end());
    cd.erase(unique(ALL(cd)), cd.end());
    ab.erase(ab.begin());
    cd.erase(cd.begin());

    int wa = ab[0];
    int sa = 0;
    double va = calc(wa, sa);
    double e = calc(100, E);
    for(auto&& wi : ab){
        for(auto&& si : cd){
            if(wi+si>F)continue;
            double v = calc(wi, si);
            if(v>e) continue;
            if(chmax(va, v)){
                wa = wi;
                sa = si;
            }
        }
    }
    pr(wa+sa, sa);
}