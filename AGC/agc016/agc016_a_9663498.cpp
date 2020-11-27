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
    string S;
    cin >> S;

    int ans = INF;
    REP(i, 26){
        char c = 'a'+i;
        string s = S;

        bool ff = true;
        for (int k = 0; k < S.size(); k++){
            if(S[k] == c){
                ff = false;
                break;
            }
        }
        if(ff) continue;

        for (int k = 0; k < S.size(); k++)
        {
            //check
            bool f = true;
            REP(j, s.size()-1){
                if(s[j] != s[j+1]){
                    f = false;
                    break;
                }
            }
            if(f){
                ans = min(ans, k);
            }

            string tmp_s;
            REP(j, s.size()-1){
                if(s[j] == c || s[j+1] == c) tmp_s.pb(c);
                else tmp_s.pb(s[j]);
            }
            s = tmp_s;
        }
    }

    pr(ans);
}