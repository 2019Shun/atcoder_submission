#include <bits/stdc++.h>
#include <vector>
#include <numeric>
#define PI 3.14159265358979323846
#define MAXINF 1e18L
#define INF 1e9L
#define EPS 1e-9
#define REP(i, n) for(int i=0;i<int(n);++i)
#define Rep(i,sta, n) for(int i=sta;i<n;i++)
#define RREP(i, n) for(int i=int(n)-1;i>=0;--i)
#define RRep(i,sta, n) for(int i=sta;i>=n;--i)
#define ALL(v) v.begin(),v.end()
#define SORT(v) sort(ALL(v))
#define RSORT(v) sort(ALL(v), greater<int>())S
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
    int n,q;
    cin >> n >> q;
    string s;
    cin >> s;

    // vector<int> v(s.size(),0);
    // int tmp = 0;
    // REP(i, s.size()-1){
    //     if(s[i] == 'A' && s[i+1] == 'C')v[i]=++tmp;
    //     else v[i]=tmp;
    // }
    // v[s.size()-1]=tmp;
    vector<int> v(n+1,0);
    REP(i, n){
        v[i+1]=v[i]+((s[i] == 'A' && s[i+1] == 'C')?1:0);
    }

    vector<int> ans(q,0);
    REP(i, q){
        int l,r;
        cin >> l >> r;
        // if(r-l==1){
        //     if(s[l-1]=='A'&&s[r-1]=='C')ans[i]=1;
        //     continue;
        // }
        // int min_n;
        // int max_n;
        // if(s[l-1]=='A'&&s[l]=='C')min_n = v[l-1];
        // else min_n = v[l-1]-1;

        // if(r==n) max_n = v[r-1];
        // else max_n = v[r];

        // ans[i]=max_n-(min_n-1);
        int minn=v[l-1];
        int maxn=v[r-1];
        ans[i]=v[r-1]-v[l-1];
    }
    REP(i, q){
        pr(ans[i]);
    }
}