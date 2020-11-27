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
    vector<ll> A(N);
    REP(i,N) {
        // ll a,b;
        // printf("%d.%d")
        // A[i] = (ll)(a * 1e9);
        std::string s;
        std::cin >> s;

        std::string g;  // 小数点以下を取り出したもの
        if (std::count(s.begin(), s.end(), '.') != 0) {
            while (s.back() != '.') {
                g.push_back(s.back());
                s.pop_back();
            }
            s.pop_back();
            std::reverse(g.begin(), g.end());
        }
        while ((int)g.length() < 9) g.push_back('0');

        // 整数に変換
        A[i] = std::stoi(s) * 1000000000LL + std::stoi(g);
    }
    vector<int> t(N), f(N);
    vector<vector<ll>> v(20, vector<ll>(20,0));
    REP(i, N){
        while((A[i]%2)==0){
            t[i]++;
            A[i] /= 2;
        }
        while((A[i]%5)==0){
            f[i]++;
            A[i] /= 5;
        }
        v[t[i]>18?18:t[i]][f[i]>18?18:f[i]]++;
    }
    ll ans = 0;
    REP(i, 20)REP(j, 20){
        REP(x, 20)REP(y, 20){
            if(i+x>=18 && j+y>=18){
                if(i==x && j==y && v[i][j] > 0) ans += v[i][j] * (v[x][y]-1);
                else ans += v[i][j] * v[x][y];
            }
        }       
    }
    pr(ans/2);

}