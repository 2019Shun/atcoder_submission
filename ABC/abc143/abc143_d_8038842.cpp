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

int main(void)
{
    int N;
    cin >> N;
    vector<int> L(N);
    for (int i = 0; i < N; i++) {
        cin >> L[i];
    }
    SORT(L);
    int ans = 0;
    REP(i, N){
        Rep(j, i+1, N){
            int l = max(L[i]-L[j], L[j]-L[i]);
            int r = L[i]+L[j];
            int l_id = upper_bound(ALL(L), l) - L.begin();
            int r_id = lower_bound(ALL(L), r) - L.begin();
            if(l_id < j) l_id = j;

            ans += r_id - l_id - 1;
            if(l_id < i && i < r_id)ans--;
            if(l_id < j && j < r_id)ans--;
            // Rep(k, j+1, N){
            //     if(L[i]<L[j]+L[k] && L[j]<L[i]+L[k] && L[k]<L[i]+L[j]) ans++;
            //     if(L[k]>=L[i]+L[j])break;
            // }
        }
    }
    pr(ans);
}