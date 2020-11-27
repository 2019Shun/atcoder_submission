#include <bits/stdc++.h>
#include <vector>
#include <numeric>
#define PI 3.14159265358979323846
#define MAXINF 1e18L
#define INF 1e9L
#define EPS 1e-9
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
using namespace std;
template<class A>void pr(A a){cout << (a) << endl;}
template<class A,class B>void pr(A a,B b){cout << a << " "  ;pr(b);}
template<class A,class B,class C>void pr(A a,B b,C c){cout << a << " " ;pr(b,c);}
template<class A,class B,class C,class D>void pr(A a,B b,C c,D d){cout << a << " " ;pr(b,c,d);}
typedef long long ll;
typedef pair<int, int> pii;

int main(void)
{
    int n;
    cin >> n;    
    vector<vector<int>> ans;
    vector<int> w(n);
    REP(i, n){
        cin >> w[i];
    }

    ans.pb(vector<int>(1, w[0]));

    Rep(i, 1, n){
        vector<pii> b;
        for (int j = 0; j < ans.size(); j++) {
            if(ans[j].back() >= w[i]){
                b.pb(make_pair(ans[j].back(), j));
            }
        }
        if(b.size()){
            SORT(b);
            ans[b[0].second].pb(w[i]);
        }else{
            ans.push_back(vector<int>(1, w[i]));
        }
    }
    pr(ans.size());
}