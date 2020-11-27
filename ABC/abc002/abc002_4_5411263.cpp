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
    int n,m;
    cin >> n >> m;
    bool v[12][12]={};
    REP(i, m){
        int x,y;
        cin>>x>>y;
        v[x-1][y-1]=v[y-1][x-1]=true;
    }

    int ans=0;
    REP(i, 1<<n){
        int cnt=0;
        bool flag=true;
        REP(j, n){
            if(!(i&(1<<j)))continue;
            cnt++;
            Rep(k, j+1, n){
                if(!(i&(1<<k)))continue;
                if(!v[j][k]){
                    flag=false;
                    break;
                }
            }
            if(!flag)break;
        }
        if(flag) ans=max(ans, cnt);
    }
    pr(ans);
}