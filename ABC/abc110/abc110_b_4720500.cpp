#include <bits/stdc++.h>
#include <vector>
#include <numeric>
#define PI 3.14159265358979323846
#define MAXINF 1e18L
#define INF 1e9L
#define EPS 1e-9
#define REP(i, n) for(int i=0;i<int(n);++i)
#define RREP(i, n) for(int i=int(n)-1;i>=0;--i)
#define ALL(v) v.begin(),v.end()
#define SORT(v) sort(ALL(v))
#define DEBUG(x) cerr<<#x<<": "<<x<<endl;
#define DEBUG_VEC(v) cerr<<#v<<":";for(int i=0;i<v.size();i++) cerr<<" "<<v[i]; cerr<<endl
#define pb push_back
using namespace std;
template<class A>void pr(A a){cout << (a) << endl;}
template<class A,class B>void pr(A a,B b){cout << a << " "  ;pr(b);}
template<class A,class B,class C>void pr(A a,B b,C c){cout << a << " " ;pr(b,c);}
template<class A,class B,class C,class D>void pr(A a,B b,C c,D d){cout << a << " " ;pr(b,c,d);}
typedef long long ll;
typedef pair<int, int> intint;

int main(void)
{
    int n,m;
    cin >> n >> m;
    int x,y;
    cin >> x >> y;
    
    vector<int> xi(n);
    for (int i = 0; i < n; i++) {
        cin >> xi[i];
    }
    vector<int> yi(m);
    for (int i = 0; i < m; i++) {
        cin >> yi[i];
    }

    SORT(xi);
    SORT(yi);
    
    if(x < yi[0] && yi[0] < y && xi[xi.size()-1] < yi[0]){
        pr("No War");
    }else{
        pr("War");
    }
}