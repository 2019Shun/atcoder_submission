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
    ll H,W,K;
    cin >> H >> W >> K;
    vector<string> S(H);
    REP(i, H) cin >> S[i];

    ll ans = MAXINF;
    REP(i, 1<<(H-1)){
        vector<int> bo(1, 0);
        ll tmp_ans = 0;
        REP(j, H-1) if(i&(1<<j)){
            bo.pb(j+1);
            tmp_ans++;
        } 
        bo.pb(H);
        int n = bo.size();
        vector<ll> tot(n-1, 0);
        vector<ll> tmp_tot(n-1, 0);
        bool f2 = false;
        REP(j, W){
            REP(k, n-1){
                Rep(l, bo[k], bo[k+1]){
                    if(S[l][j]=='1')tmp_tot[k]++;
                }
            }
            bool f = true;
            REP(k, n-1){
                if(tmp_tot[k]+tot[k] > K) f = false;            
            }

            if(!f){
                REP(k, n-1) {
                    tot[k] = tmp_tot[k];
                    tmp_tot[k] = 0;
                }
                tmp_ans++;
            }
            else {
                REP(k, n-1) {
                    tot[k] += tmp_tot[k];
                    tmp_tot[k] = 0;    
                }
                f2 = true;
            }
        }
        if(f2) chmin(ans, tmp_ans);
    }

    // REP(i, H){
    //     reverse(ALL(S[i]));
    // }
    // REP(i, 1<<(H-1)){
    //     vector<int> bo(1, 0);
    //     int tmp_ans = 0;
    //     REP(j, H-1) if(i&(1<<j)){
    //         bo.pb(j+1);
    //         tmp_ans++;
    //     } 
    //     bo.pb(H);
    //     int n = bo.size();
    //     vector<int> tot(n-1, 0);
    //     vector<int> tmp_tot(n-1, 0);
    //     REP(j, W){
    //         REP(k, n-1){
    //             Rep(l, bo[k], bo[k+1]){
    //                 if(S[l][j]=='1')tmp_tot[k]++;
    //             }
    //         }
    //         bool f = true;
    //         REP(k, n-1){
    //             if(tmp_tot[k]+tot[k] > K) f = false;            
    //         }

    //         if(!f){
    //             REP(k, n-1) {
    //                 tot[k] = tmp_tot[k];
    //                 tmp_tot[k] = 0;
    //             }
    //             tmp_ans++;
    //         }
    //         else {
    //             REP(k, n-1) {
    //                 tot[k] += tmp_tot[k];
    //                 tmp_tot[k] = 0;    
    //             }
    //         }
    //     }
    //     chmin(ans, tmp_ans);
    // }
    pr(ans);
}