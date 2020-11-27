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

int n;
vector<map<string,int>> memo;

bool check(string s){
    if(s.size() != 4) return false;
    if(s[0]=='A' && s[1]=='G' && s[2]=='C') return true;
    if(s[0]=='A' && s[1]=='C' && s[2]=='G') return true;
    if(s[0]=='G' && s[1]=='A' && s[2]=='C') return true;
    if(s[1]=='A' && s[2]=='G' && s[3]=='C') return true;
    if(s[1]=='A' && s[2]=='C' && s[3]=='G') return true;
    if(s[1]=='G' && s[2]=='A' && s[3]=='C') return true;
    if(s[0]=='A' && s[1]=='G' && s[3]=='C') return true;
    if(s[0]=='A' && s[2]=='G' && s[3]=='C') return true;
    return false;
}

int dfs(int cur, string last3){
    if(memo[cur].count(last3)) return memo[cur][last3];
    if(cur==n) return 1;
    int ret = 0;
    string agct="AGCT";
    REP(i, 4){
        char c = agct[i];
        if(!check(last3 + c)){
            string s = "aaa";
            s[0]=last3[1];
            s[1]=last3[2];
            s[2]=c;
            ret = (ret + dfs(cur+1,s)) % 1'000'000'007;
        }
    }
    memo[cur][last3] = ret;
    return ret;
}

int main(void)
{
    cin >> n;
    memo = vector<map<string,int>>(n+1);
    pr(dfs(0,"TTT"));
}