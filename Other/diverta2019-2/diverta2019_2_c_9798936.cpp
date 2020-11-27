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
template<class T> inline bool chmin(T& a, T b){return a>b ? a=b, true : false;}
template<class T> inline bool chmax(T& a, T b){return a<b ? a=b, true : false;}
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll,ll> pll;

int main(void)
{
    int N;
    cin >> N;
    vector<ll> A_org(N);
    for (int i = 0; i < N; i++) {
        cin >> A_org[i];
    }

    vector<ll> A = A_org;
    SORT(A);
    vector<pll> p;
    Rep(i, 1, N-1){
        if(A.front() <= 0 && 0 <= A.back()){
            if(A[i] < 0){
                p.emplace_back(A.back(), A[i]);
                A.back() -= A[i]; 
            }else{
                p.emplace_back(A.front(), A[i]);
                A.front() -= A[i];
            }
        }else if(A.front() >= 0){
            p.emplace_back(A.front(), A[i]);
            A.front() = -abs(A.front() - A[i]);
        }else{
            p.emplace_back(A.back(), A[N-2]);
            A.back() = A.back() - A[N-2];
            for(int j = N-2; j > i; j--) A[j] = A[j-1]; 
        }
    }

    ll ans = abs(A.back() - A.front());
    p.emplace_back(A.back(), A.front());

    pr(ans);
    for(auto&& pi : p) pr(pi.fi, pi.se);

    // A = A_org;
    // for(auto&& ai : A) ai = -ai;
    // SORT(A);
    // vector<pll> q;
    // Rep(i, 1, N-1){
    //     if(A.front() < 0 && 0 < A.back()){
    //         if(A[i] < 0){
    //             q.emplace_back(A.back(), A[i]);
    //             A.back() -= A[i]; 
    //         }else{
    //             q.emplace_back(A.front(), A[i]);
    //             A.front() -= A[i];
    //         }
    //     }else{
    //         q.emplace_back(A.front(), A[i]);
    //         A.front() = -abs(A.front() - A[i]);
    //     }
    // }

    // // ll ans_b = abs(A.back() - A.front());
    // ll ans_b = -INF;
    // q.emplace_back(A.back(), A.front());

    // pr(ans_a>=ans_b?ans_a:ans_b);
    // if(ans_a >= ans_b) for(auto&& pi : p) pr(pi.fi, pi.se);
    // else for(auto&& qi : q) pr(-qi.fi, -qi.se);
}