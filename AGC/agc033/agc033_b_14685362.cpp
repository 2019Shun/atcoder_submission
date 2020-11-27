#include <bits/stdc++.h>
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
template<class T> void pr_vec(vector<T> &v, char ep=' '){int n=v.size();REP(ni,n){cout<<v[ni];if(ni!=n-1)cout<<ep;}cout<<endl;};
template<class T> inline bool chmin(T& a, T b){return a>b ? a=b, true : false;}
template<class T> inline bool chmax(T& a, T b){return a<b ? a=b, true : false;}
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll,ll> pll;

int main(void)
{
    int H,W,N;
    cin >> H >> W >> N;
    int sr,sc;
    cin >> sr >> sc;
    string S,T;
    cin >> S >> T;

    pii s1={1,H}, s2={1,W};
    RREP(i, N){
        switch (T[i])
        {
        case 'L': s2.se = min(s2.se+1, W);break;
        case 'R': s2.fi = max(s2.fi-1, 1);break;
        case 'U': s1.se = min(s1.se+1, H);break;
        case 'D': s1.fi = max(s1.fi-1, 1);break;
        }
        switch (S[i])
        {
        case 'L': s2.fi++;break;
        case 'R': s2.se--;break;
        case 'U': s1.fi++;break;
        case 'D': s1.se--;break;
        }
        if(s1.fi>s1.se||s2.fi>s2.se){
            pr("NO");
            return 0;
        }
    }
    YES(s1.fi<=sr&&sr<=s1.se&&s2.fi<=sc&&sc<=s2.se);
}