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
    int n,k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<int> v; 
    if(s[0] == '0') v.pb(0);
    v.pb(0);
    Rep(i, 1, n){
       if(s[i-1] == s[i]) continue;
        v.pb(i);
    }
    v.pb(n);
    if(s[s.size()-1]=='0') v.pb(n);
    
    vector<int> ans;    
    for (int i = 1; i < n; i+=2) {
        int mid = i + k *2;
        if(mid >= v.size()) break; 
        ans.pb(v[mid] - v[i-1]);
    }

    if(ans.size() == 0){
        REP(i, v.size()){
            if(i%2) ans.pb(v[i]);
        }
    }
    RSORT(ans);
    pr(ans[0]);
}