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
    int n;
    cin >> n;
    string s;
    cin >> s;

    vector<int> v;

    if(n == 1) {
        pr(0);
        return 0;
    }

    if(s[0] == '#') v.pb(0);

    int tmp = 0;
    int rw = 0; //右の白
    Rep(i, 1, n){
        tmp++;
        if(s[i-1] != s[i]){
            v.pb(tmp);
            if(v.size() % 2) rw += tmp;
            tmp = 0;
        }
    }
    v.pb(++tmp);
    if(v.size() % 2) rw += tmp;
    if(s[s.size()-1] == '#') v.pb(0);

    int lb = 0;
    vector<int> ans;
    REP(i, v.size()){
        if(i%2==0){ //siro
            rw -= v[i];
        }else{
            lb += v[i];
        }
        ans.pb(lb+rw);
    }

    SORT(ans);
    pr(ans.size() == 0?0:ans[0]);
}