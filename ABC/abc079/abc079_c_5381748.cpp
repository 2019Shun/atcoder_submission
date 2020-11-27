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

vector<int> a(4);
void dfs(string s, string& c){
    if(s.size()==3){
        int ans=a[0];
        if(s[0]=='+')ans+=a[1];
        else ans-=a[1];
        if(s[1]=='+')ans+=a[2];
        else ans-=a[2];
        if(s[2]=='+')ans+=a[3];
        else ans-=a[3];

        if(ans==7){
            c=s;
        }
        return;
    }


    dfs(s+'+',c);
    dfs(s+'-',c);
}

int main(void)
{
    REP(i, 4){
        char c;cin >> c;
        a[i] = c-'0';
    }
    string s,c;
    dfs(s,c);
    cout << a[0] << c[0] << a[1] << c[1] << a[2] << c[2] << a[3] << "=7" << endl;
}