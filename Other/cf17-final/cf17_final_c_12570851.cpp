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

int minTime(vector<int> &arr) {
    int time = 24;
    vector<int> c;
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] >= 1) c.push_back(i);
    }
    for (int i = 0; i < c.size() - 1; i++) time = min(time, c[i + 1] - c[i]);
    time = min(time, 24 - c.back());
    return time;
}

int main(void)
{
    int N;
    cin >> N;
    vector<int> D(13,0);
    D[0]++;//takahashi
    for (int i = 0; i < N; i++) {
        int d;
        cin >> d;
        D[d]++;
    }
    if(D[0] >= 2){
        pr(0);
        return 0;
    }

    int ans = 0;
    REP(i, 1<<13){
        vector<int> e(24,0);
        e[0]=1;
        Rep(j, 1, 13){
            if(D[j]==0)continue;
            else if(D[j]==2){
                if(j==0||j==12){
                    pr(0);return 0;
                }
                e[j] = 1;
                e[24-j] = 1;
            }else if(D[j]>2){
                pr(0);return 0;
            }
            else if(i&(1<<j)){
                e[j] = 1;
            }else{
                e[24-j] = 1;
            }
        }
        vector<int> ei;
        REP(j, 24){
            if(e[j]>=1) ei.pb(j);
        }
        int tmp = 24-ei.back();
        REP(i, ei.size()-1){
            chmin(tmp, ei[i+1]-ei[i]);
        }
        chmax(ans, tmp);
        // if(ei.size()==2){
        //     chmax(ans, chmin(ei.back(), 24-ei.back()));
        // }else{
        //     int tmp = ei.back()>12?24-ei.back():ei.back();
        //     REP(i, ei.size()-1){
        //         chmin(tmp, ei[i+1]-ei[i]);
        //     }
        //     chmax(ans, tmp);
        // }
        // chmax(ans, minTime(e));
    }
    pr(ans);
}