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

map<ll, int> prime_factor(ll n){
    map<ll, int> res;
    for(ll i = 2; i*i <= n; i++){
        while (n % i == 0){
            res[i]++;
            n /= i;
        }
    }
    if(n != 1) res[n]++;
    return res;
}

bool is_prime(int n){
    for (int i = 2; i * i <= n; i++) {
        if(n % i == 0) return false;
    }
    return true;
}

int main(void)
{
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    SORT(A);
    vector<int> p(1000010);
    vector<int> ok(N, 1);
    REP(i, N-1){
        //同じものを除去
        if(A[i+1]==A[i]){
            ok[i+1] = ok[i] = 0;   
            p[A[i]] = 1;
        }
    }

    int ans = 0;
    REP(j, N){
        if(ok[j]==1){
            vector<ll> d;
            for (ll i = 1; i*i <= A[j]; i++) {
                if(A[j]%i==0) {
                    d.pb(i);
                    if(i*i != A[j]) d.pb(A[j]/i); //Nが平方数である時の対策
                }
            }
            bool f = true;
            for(auto&& di:d){
                if(p[di]==1){
                    f = false;
                    break;
                }
            }
            if(f) ans++;
            p[A[j]] = 1;
        }
    }
    pr(ans);
}