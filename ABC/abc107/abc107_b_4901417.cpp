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
#define SORT(v) sort(ALL(v))
#define RSORT(v) sort(ALL(v));reverse(ALL(v))
#define FIND(v,x) (binary_search(ALL(v),(x)))
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
    int h,w;
    cin >> h >> w;
    vector<vector<int>> a(h, vector<int>(w));
    vector<int> h_id, w_id;

    REP(i, h){
        bool flag = true;
        REP(j, w){
            char tmp;
            cin >> tmp;
            if(tmp == '#') {
                a[i][j]=1;
                flag = false;
            }
            else a[i][j]=0;
        }
        if(flag==true)h_id.pb(i);
    }

    REP(i, w){
        bool flag = true;
        REP(j, h){
            if(a[j][i]==1) flag = false;
        }
        if(flag==true)w_id.pb(i);
    }

    REP(i, h){
        if(FIND(h_id,i)) continue;
        REP(j, w){
            if(FIND(w_id,j)) continue;
            cout << (a[i][j]==1 ? '#' : '.');
        }
        cout << endl;
    }
}