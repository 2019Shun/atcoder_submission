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
    int H,W,N,M;
    cin >> H >> W >> N >> M;
    vector<vector<int>> t(H, vector<int>(W));
    vector<vector<int>> light_H(H), light_W(W), brock_H(H), brock_W(W);
    REP(i, N){
        int a,b;
        cin >> a >> b;
        light_H[a-1].pb(b-1);
        light_W[b-1].pb(a-1);
        t[a-1][b-1] = 1;
    }
    REP(i, M){
        int a,b;
        cin >> a >> b;
        brock_H[a-1].pb(b-1);
        brock_W[b-1].pb(a-1);
        t[a-1][b-1] = -1;
    }

    REP(i, H){
        SORT(light_H[i]);
        SORT(brock_H[i]);
    }
    REP(i, W){
        SORT(light_W[i]);
        SORT(brock_W[i]);
    }

    int ans = 0;
    REP(h, H)REP(w, W){
        if(t[h][w] == 1) {
            // pr(h, w);
            ans++;
            continue;
        }else if(t[h][w] == -1){
            continue;
        }

        {
            //自身より左側の光源とブロックの状況を取得
            int light_l;
            auto light_l_it = lower_bound(ALL(light_H[h]), w);
            if(light_l_it == light_H[h].begin()) light_l = -1;
            else light_l = *(light_l_it-1);
            int brock_l;
            auto brock_l_it = lower_bound(ALL(brock_H[h]), w);
            if(brock_l_it == brock_H[h].begin()) brock_l = -1;
            else brock_l = *(brock_l_it-1);

            int light_r;
            auto light_r_it = lower_bound(ALL(light_H[h]), w);
            if(light_r_it == light_H[h].end()) light_r = -1;
            else light_r = *light_r_it;
            int brock_r;
            auto brock_r_it = lower_bound(ALL(brock_H[h]), w);
            if(brock_r_it == brock_H[h].end()) brock_r = 10000;
            else brock_r = *brock_r_it;

            if((light_l != -1 && brock_l < light_l) || (light_r < brock_r && light_r != -1)) {
                ans++;
                // pr(h, w);
                continue;
            }
        }

        {
            int light_l;
            auto light_l_it = lower_bound(ALL(light_W[w]), h);
            if(light_l_it == light_W[w].begin()) light_l = -1;
            else light_l = *(light_l_it-1);
            int brock_l;
            auto brock_l_it = lower_bound(ALL(brock_W[w]), h);
            if(brock_l_it == brock_W[w].begin()) brock_l = -1;
            else brock_l = *(brock_l_it-1);

            int light_r;
            auto light_r_it = lower_bound(ALL(light_W[w]), h);
            if(light_r_it == light_W[w].end()) light_r = -1;
            else light_r = *light_r_it;
            int brock_r;
            auto brock_r_it = lower_bound(ALL(brock_W[w]), h);
            if(brock_r_it == brock_W[w].end()) brock_r = 10000;
            else brock_r = *brock_r_it;

            if((light_l != -1 && brock_l < light_l) || (light_r < brock_r && light_r != -1)) {
                ans++;
                // pr(h, w);
                continue;
            }
        }
    }

    pr(ans);
}