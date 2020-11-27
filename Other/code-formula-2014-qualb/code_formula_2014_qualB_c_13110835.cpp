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
    string A,B;
    cin >> A >> B;
    int n = A.size();
    string S,T;
    vector<int> x(26);
    vector<int> y(26);
    REP(i, n){
        if(A[i]!=B[i]){
            S+=A[i];T+=B[i];
        }
        x[A[i]-'a']++;
        y[B[i]-'a']++;
    }

    n = S.size();
    if(x!=y||n>6){
        pr("NO");return 0;
    }

    // bool fe = 0;
    // REP(i, n){
    //     REP(j, 26){
    //         if(y[j]==1&&(T[i]-'a')==j) fe = true;
    //     }
    // }

    bool fe = *max_element(y.begin(),y.end())>1;

    bool f = false;
    if(fe) f |= S==T;
    REP(i0, n)REP(j0, i0){
        swap(T[i0],T[j0]);
        if(fe&&S==T) f = true; 
        REP(i1, n)REP(j1, i1){
            swap(T[i1],T[j1]);
            if(fe&&S==T) f = true; 
            REP(i2, n)REP(j2, i2){
                swap(T[i2],T[j2]);
                if(T==S){
                    f = true;
                }
                swap(T[i2],T[j2]);
            }
            swap(T[i1],T[j1]);
        }
        swap(T[i0],T[j0]);
    }

    YES(f);
}