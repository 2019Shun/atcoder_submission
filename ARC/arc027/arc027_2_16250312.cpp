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

int main(void)
{
    int N;
    cin >> N;
    string S,T;
    cin >> S >> T;
    
    auto is_num = [](char c){return '0' <= c && c <= '9';};

    map<int, int> m;
    REP(k, 100) REP(i, N){
        if((is_num(S[i])&&is_num(T[i]))||(!is_num(S[i])&&!is_num(T[i]))) continue;

        if(is_num(S[i])) m[T[i]] = S[i];
        else m[S[i]] = T[i];

        REP(j, N){
            if(m.count(S[j])) S[j] = m[S[j]];
            if(m.count(T[j])) T[j] = m[T[j]];
        }
    }

    ll ans = 1;
    vector<int> ok(1000);
    REP(i, N){
        if((is_num(S[i])&&is_num(T[i]))) continue;
        if(ok[S[i]]||ok[T[i]]) continue;
        
        if(i==0) ans *= 9;
        else ans *=10;

        ok[S[i]] = 1;
        ok[T[i]] = 1;
    }

    pr(ans);
}