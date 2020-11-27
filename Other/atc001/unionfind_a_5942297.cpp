#include <bits/stdc++.h>
#include <vector>
#include <numeric>
#define PI 3.14159265358979323846
#define MAXINF (1e18L)
#define INF (1e9L)
#define EPS (1e-9)
#define MOD (1'000'000'007)
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
#define fi first
#define se second
using namespace std;
template<class A>void pr(A a){cout << (a) << endl;}
template<class A,class B>void pr(A a,B b){cout << a << " "  ;pr(b);}
template<class A,class B,class C>void pr(A a,B b,C c){cout << a << " " ;pr(b,c);}
template<class A,class B,class C,class D>void pr(A a,B b,C c,D d){cout << a << " " ;pr(b,c,d);}
typedef long long ll;
typedef pair<int, int> pii;

class union_find{
public:
    vector<int> parent;
    union_find(int n) : parent(vector<int>(n, -1)) {} //Parent is -(size of set)
    int root(int a){ return (parent[a] < 0 ? a : parent[a] = root(parent[a])); }
    int size(int a){ return -parent[root(a)]; }
    bool same(int &a, int &b){a=root(a);b=root(b); return (a==b); }
    bool connect(int a, int b){
        if(same(a,b)) return false;
        if(size(a)<size(b)) a^=b^=a^=b;
        parent[a] += parent[b]; parent[b]=a;
        return true;
    }
};

int main(void)
{
    int n,q;
    cin >> n >> q;
    
    union_find uf(n);
    vector<int> yes;
    REP(i, q){
        int p,a,b;
        cin >> p >> a >> b;
        if(p) yes.pb(uf.same(a,b));
        else uf.connect(a,b);
    }

    for (auto i : yes) Yes(i);
}