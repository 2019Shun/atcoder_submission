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
    string T;
    cin >> T;
    ll A = 10000000000;
    
    if(N<=3){
        if(N==3){
            if(T[0]=='1'&&T[1]=='1'&&T[2]=='0') pr(A);
            else if(T[0]=='1'&&T[1]=='0'&&T[2]=='1') pr(A-1);
            else if(T[0]=='0'&&T[1]=='1'&&T[2]=='1') pr(A-1);
            else pr(0);
        }else if(N==2){
            if(T[0]=='1'&&T[1]=='1') pr(A);
            else if(T[0]=='1'&&T[1]=='0') pr(A);
            else if(T[0]=='0'&&T[1]=='1') pr(A-1);
            else pr(0);
        }else if(N==1){
            if(T[0]=='1') pr(A*2);
            else if(T[0]=='0') pr(A);
            else pr(0);
        }
        return 0;
    }

    //N>=3の場合
    int n = 0;
    if(T[0]=='1'&&T[1]=='0'){
        T = T.substr(2, N-2);
        n++;
    }else if(T[0]=='0'){
        T = T.substr(1, N-1);
        n++;
    }
    //途中の110
    N = T.size();
    for (int i = 2; i < N; i+=3)
    {
        if(T[i-2]=='1'&&T[i-1]=='1'&&T[i]=='0'){
            n++;
        }else{
            pr(0);
            return 0;
        }
    }
    //末尾
    if((N%3)==2){
        if(T[N-2]=='1'&&T[N-1]=='1'){
            n++;
        }else{
            pr(0);
            return 0; 
        }
    }else if((N%3)==1){
        if(T[N-1]=='1'){
            n++;
        }else{
            pr(0);
            return 0; 
        }
    }

    pr(A-n+1);
}