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

struct HashPair {

    //注意 constがいる
    template<class T1, class T2>
    size_t operator()(const pair<T1, T2> &p) const {

        //first分をハッシュ化する
        auto hash1 = hash<T1>{}(p.first);

        //second分をハッシュ化する
        auto hash2 = hash<T2>{}(p.second);

        //重複しないようにハッシュ処理
        size_t seed = 0;
        seed ^= hash1 + 0x9e3779b9 + (seed << 6) + (seed >> 2);
        seed ^= hash2 + 0x9e3779b9 + (seed << 6) + (seed >> 2);
        return seed;
    }
};

int p[5010][5010];

int main(void)
{
    int N;
    cin >> N;
    vector<pii> v(N);
    REP(i, N) cin >> v[i].fi >> v[i].se;
    // unordered_map<pii, int, HashPair> mp;
    // REP(i, N) mp[v[i]]++;

    // vector<vector<int>> p(5010, vector<int>(5010));
    REP(i, N){
        p[v[i].fi][v[i].se]++;
    }

    auto f = [](pii &p1, pii &p2){
        return p1.fi>=0&&p1.se>=0&&p2.fi>=0&&p2.se>=0&&p1.fi<=5000&&p1.se<=5000&&p2.fi<=5000&&p2.se<=5000;
    };

    int ans = 0;
    REP(i, N){
        REP(j,i){
            pii p1, p2;
            p1.fi = v[i].fi + abs(v[i].se-v[j].se);
            p1.se = v[i].se + abs(v[i].fi-v[j].fi);
            p2.fi = v[j].fi + abs(v[i].se-v[j].se);
            p2.se = v[j].se + abs(v[i].fi-v[j].fi);
            // if(mp[p1] > 0 && mp[p2] > 0){
            if(f(p1, p2) && p[p1.fi][p1.se] > 0 && p[p2.fi][p2.se] > 0){
                chmax(ans,  abs(v[i].se-v[j].se)*abs(v[i].se-v[j].se)+abs(v[i].fi-v[j].fi)*abs(v[i].fi-v[j].fi));
            }
            p1.fi = v[i].fi - abs(v[i].se-v[j].se);
            p1.se = v[i].se - abs(v[i].fi-v[j].fi);
            p2.fi = v[j].fi - abs(v[i].se-v[j].se);
            p2.se = v[j].se - abs(v[i].fi-v[j].fi);
            // if(mp[p1] > 0 && mp[p2] > 0){
            if(f(p1, p2) && p[p1.fi][p1.se] > 0 && p[p2.fi][p2.se] > 0){
                chmax(ans,  abs(v[i].se-v[j].se)*abs(v[i].se-v[j].se)+abs(v[i].fi-v[j].fi)*abs(v[i].fi-v[j].fi));
            }            
        }
    }
    pr(ans);
}