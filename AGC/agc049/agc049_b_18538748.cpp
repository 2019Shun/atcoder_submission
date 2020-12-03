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

struct BIT{
    vector<ll> bit; 
    int n;
    BIT(int n) : n(n), bit(vector<ll>(n+1, 0)) {}
    //[1,i]までの合計を計算．1-indexed
    ll sum(int i){
        ll s = 0;
        while(i > 0){
            s += bit[i];
            i -= i & -i;
        }
        return s;
    }
    //sum(j)-sum(i-1)で[i,j]までの合計を計算．1-indexed
    ll between(int i, int j){
        if(i > j) return 0;
        return sum(j) - sum(i-1);
    }
    //i番目にxを加える．1-indexed
    void add(int i, int x){
        while(i <= n){
            bit[i] += (ll)x;
            i += i & -i;
        }
    }
    //x以上の値(区間和)が現れる最初のインデックス
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
    //xより大きい値(区間和)が現れる最初のインデックス
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
};

int main(void)
{
    int N;
    cin >> N;
    string S,T;
    cin >> S >> T;
    int s1 = count(ALL(S), '1');
    int t1 = count(ALL(T), '1');

    if(s1<t1 || ((s1-t1)%2)){
        pr(-1);
        return 0;
    }

    BIT bit(N);
    REP(i, N) if(S[i]=='1') bit.add(i+1, 1);

    ll ans = 0;
    REP(i, N){
        if(S[i]==T[i]) continue;
        if(S[i]=='1'&&T[i]=='0'){
            //次の1が出てくるインデックスを探す．0-indexed仮定
            int next1_id = bit.upper_bound(bit.sum(i+1))-1;

            if(next1_id==N-1&&S[next1_id]!='1'){
                pr(-1);
                return 0;
            }

            //値の更新
            S[i] = S[next1_id] = '0';
            bit.add(i+1, -1);
            bit.add(next1_id+1, -1);

            //答えの更新
            ans += (next1_id - i);
        }else if(S[i]=='0'&&T[i]=='1'){
            //次の1が出てくるインデックスを探す．0-indexed仮定
            int next1_id = bit.upper_bound(bit.sum(i+1))-1;

            if(next1_id==N-1&&S[next1_id]!='1'){
                pr(-1);
                return 0;
            }

            S[i] = '1';
            S[next1_id] = '0';
            bit.add(i+1, 1);
            bit.add(next1_id+1, -1);

            //答えの更新
            ans += (next1_id - i);
        }
    }

    pr(ans);
}