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
    string S;
    cin >> N >> S;

    auto f = [N,S](string &s){
        Rep(i, 1, N-1){
            if(s[i] == 'S'){
                if(S[i]=='o') {
                    if(s[i-1]=='S') s.pb('S');
                    else s.pb('W');
                }else{
                    if(s[i-1]=='S') s.pb('W');
                    else s.pb('S');   
                }
            }else{
                if(S[i]=='o') {
                    if(s[i-1]=='S') s.pb('W');
                    else s.pb('S');
                }else{
                    if(s[i-1]=='S') s.pb('S');
                    else s.pb('W');   
                }
            }
        }
        bool t1 = false;
        if(s[N-1]=='S') {
            if(S[N-1]=='o') t1 = s[N-2]==s[0];
            else t1 = s[N-2]!=s[0];
        }
        else {
            if(S[N-1]=='o') t1 = s[N-2]!=s[0];
            else t1 = s[N-2]==s[0];
        }
        bool t2 = false;
        if(s[0]=='S') {
            if(S[0]=='o') t2 = s[N-1]==s[1];
            else t2 = s[N-1]!=s[1];
        }
        else {
            if(S[0]=='o') t2 = s[N-1]!=s[1];
            else t2 = s[N-1]==s[1];
        }

        return (t1 && t2);
    };

    string ans = "SS";
    if(f(ans)) {
        pr(ans);
        return 0;
    }
    ans = "SW";
    if(f(ans)) {
        pr(ans);
        return 0;
    }
    ans = "WW";
    if(f(ans)) {
        pr(ans);
        return 0;
    }
    ans = "WS";
    if(f(ans)) {
        pr(ans);
        return 0;
    }
    pr(-1);
}