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
#define DEBUG(x) cerr<<#x<<': '<<x<<endl;
#define DEBUG_VEC(v) cerr<<#v<<':';for(int i=0;i<v.size();i++) cerr<<' '<<v[i]; cerr<<endl
#define Yes(n) cout<<((n)?'Yes':'No')<<endl
#define pb push_back
using namespace std;
template<class A>void pr(A a){cout << (a) << endl;}
template<class A,class B>void pr(A a,B b){cout << a << ' '  ;pr(b);}
template<class A,class B,class C>void pr(A a,B b,C c){cout << a << ' ' ;pr(b,c);}
template<class A,class B,class C,class D>void pr(A a,B b,C c,D d){cout << a << ' ' ;pr(b,c,d);}
typedef long long ll;
typedef pair<int, int> pii;

int count(string s){
    int ans = 0;
    REP(i, s.size()-2){
        if(s[i]=='A' && s[i+1]=='B')ans++;
    }
    return ans;
}

int main(void)
{
    int n;
    cin >> n;
    int a = 0, b = 0, ab = 0;
    int ans = 0;
    REP(i, n){
        string s;
        cin >> s;
        ans += count(s);
        if(s[0] == 'B' && s[s.size()-1] == 'A') ab++;
        else if(s[0] == 'B') b++;
        else if(s[s.size()-1] == 'A') a++;
    }
    if(a>0&&b>0){
        ans += ab+1;
        a -= 1;
        b -= 1;
    }else if(a>0){
        ans += ab;
        a -= 1;  
    }else if(b>0){
        ans += ab;
        b -= 1;  
    }else{
        ans+=(ab==0)?0:ab-1; 
    }
    ans += min(a,b); 
    pr(ans);
}