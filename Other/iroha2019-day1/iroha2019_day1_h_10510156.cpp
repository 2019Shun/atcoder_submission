#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
typedef pair<ll, P>IP;
typedef vector<ll> V;
typedef vector<V> V2;
typedef vector<vector<P> > G;
void g_dir(G &graph, ll a, ll b, ll w = 1){graph[a].push_back(P(b, w));}
void g_undir(G &graph, ll a, ll b, ll w = 1){g_dir(graph, a, b, w);g_dir(graph, b, a, w);}
#define rep(i, n) for(ll (i) = 0; (i) < (n); (i)++)
#define rep1(i, n) for(ll (i) = 1; (i) <= (n); (i)++)
#define rrep(i, n) for(ll (i) = (n) - 1; (i) >= 0; (i)--)
#define rrep1(i, n) for(ll (i) = (n); (i) >= 1; (i)--)
template<class T> void chmax(T &a, const T &b){if(a < b){a = b;}}
template<class T> void chmin(T &a, const T &b){if(a > b){a = b;}}
const ll INF = 1145141919;
const ll MOD = 1000000007;
const ll NUM = 101010;
 
int main(){
    
    string N;
    cin >> N;
    
    if(N.size() == 1){
        N[0]--;
        N = "1" + N;
    }
    else if(N == string(N.size(), '9')){
        N = "18" + N.substr(1);
    }
    else if(N.substr(1) == string(N.size() - 1, '9')){
        N[0]++;
        N[1]--;
    }
    else{
        ll sum = 0;
        rep(i, N.size())sum += N[i] - '0';
        stringstream ss;
        for(;sum > 0; sum -= 9){
            ss << min(9LL, sum);
        }
        N = ss.str();
        reverse(N.begin(), N.end());
    }
    cout << N << endl;
    
    return 0;
}