#include <bits/stdc++.h>
#include <vector>
#include <numeric>
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

struct BIT{
    vector<ll> bit; //1-indexed
    int n;
    BIT(int n) : n(n), bit(vector<ll>(n+1, 0)) {}
    ll sum(int i){
        ll s = 0;
        while(i > 0){
            s += bit[i];
            i -= i & -i;
        }
        return s;
    }
    void add(int i, int x){
        while(i <= n){
            bit[i] += (ll)x;
            i += i & -i;
        }
    }
    //xより大きい値(区間和)が現れる最初のインデックス. (l,u]の範囲
    int lower_bound(ll x) {
        ll ret = 0;
        ll k = 1;
        while(2 * k <= n) k <<= 1;
        for(; k > 0; k >>= 1) {
            if(ret + k < n && bit[ret + k] < x) {
                x -= bit[ret + k];
                ret += k;
            }
        }
        return ret + 1;
    }
    //x以上の値(区間和)が現れる最初のインデックス. [l,u)の範囲
    int upper_bound(ll x) {
        ll ret = 0;
        ll k = 1;
        while(2 * k <= n) k <<= 1;
        for(; k > 0; k >>= 1) {
            if(ret + k < n && bit[ret + k] <= x) {
                x -= bit[ret + k];
                ret += k;
            }
        }
        return ret + 1;
    }
    ll between(int i, int j){
        if(i > j) return 0;
        return sum(j) - sum(i-1);
    }
};

int main(void)
{
    int n;
    cin >> n;
    BIT a(n);
    BIT b(n);
    for (int i = 0; i < n; i++) {
        ll ai;
        cin >> ai;
        a.add(i+1, ai);
        b.add(i+1, ai);
    }

    ll ans = 0;
    REP(i, n){
        auto a_sum = a.sum(i+1);
        if((i&1)==0){
            if(a_sum > 0){
                a.add(i+1, -(abs(a_sum)+1));
                ans += abs(a_sum)+1;
            }
            else if(a_sum == 0){
                a.add(i+1, -1);
                ans += 1;   
            }
        }else{
            if(a_sum < 0){
                a.add(i+1, (abs(a_sum)+1));
                ans += abs(a_sum)+1;
            }
            else if(a_sum == 0){
                a.add(i+1, 1);
                ans += 1;   
            }
        }
    }

    ll ans1 = 0;
    REP(i, n){
        auto b_sum = b.sum(i+1);
        if((i&1)==1){
            if(b_sum > 0){
                b.add(i+1, -(abs(b_sum)+1));
                ans1 += abs(b_sum)+1;
            }
            else if(b_sum == 0){
                b.add(i+1, -1);
                ans1 += 1;   
            }
        }else{
            if(b_sum < 0){
                b.add(i+1, (abs(b_sum)+1));
                ans1 += abs(b_sum)+1;
            }
            else if(b_sum == 0){
                b.add(i+1, 1);
                ans1 += 1;   
            }
        }
    }
    pr(min(ans, ans1));
}