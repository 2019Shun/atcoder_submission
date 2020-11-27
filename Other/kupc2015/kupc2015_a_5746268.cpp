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

int solve(string s){
    int ans = 0;
    if(s.size() < 5) return ans;
    REP(i, s.size()-4){
        if(s[i]=='t' && s[i+1]=='o' && s[i+2]=='k' && s[i+3]=='y' && s[i+4]=='o'){
            ans++;
            i += 4;
        }
        else if(s[i]=='k' && s[i+1]=='y' && s[i+2]=='o' && s[i+3]=='t' && s[i+4]=='o'){
            ans++;
            i += 4;
        }
    }
    return ans;
}

int main(void)
{
    int n;
    cin >> n;
    vector<int> ans(n);
    REP(i, n){
        string s;
        cin >> s;
        ans[i] = solve(s);
    }
    REP(i, n){
        pr(ans[i]);
    }
}