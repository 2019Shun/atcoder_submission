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
typedef pair<pii, int> ppi;
typedef pair<ll,ll> pll;

int x,y;
vector<int> h, v;
int end_r;

int main(void)
{
    string s;
    cin >> s;
    cin >> x >> y;

    int n = s.size();
    int hv = 0;
    int prev_t = 0;
    REP(i, n){
        if(s[i]=='T'){
            if(!hv) h.pb(i-prev_t);
            else v.pb(i-prev_t);
            hv++;hv %= 2;
            prev_t = i+1;
        }
    }
    if(prev_t != n){
        if(!hv) h.pb(n-prev_t);
        else v.pb(n-prev_t);
    }
    
    int nh = h.size(), nv = v.size();

    vector<set<int>> vx(nh);
    vx[0].insert(h[0]);
    Rep(i,1,nh){
        REPA(cx, vx[i-1]){
            vx[i].insert(cx+h[i]);
            vx[i].insert(cx-h[i]);
        }
    }
    if(vx[nh-1].find(x)==vx[nh-1].end()){
        pr("No");
        return 0;
    }

    if(nv==0){
        pr("Yes");
        return 0;
    }

    vector<set<int>> vy(nv);
    vy[0].insert(v[0]);
    vy[0].insert(-v[0]);
    Rep(i,1,nv){
        REPA(cx, vy[i-1]){
            vy[i].insert(cx+v[i]);
            vy[i].insert(cx-v[i]);
        }
    }
    if(vy[nv-1].find(y)==vy[nv-1].end()){
        pr("No");
        return 0;
    }


    pr("Yes");
}