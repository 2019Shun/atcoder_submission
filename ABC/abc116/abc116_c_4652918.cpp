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

int count_group(vector<int> v){
    int ret = 0;
    int prev = v[0];

    for (int i = 1; i < v.size(); i++) {
        if(v[i] == 0 && prev != 0){
            ret++;
        }
        prev = v[i];
    }
    return ret;
}

int main(void)
{
    int n;
    cin >> n;
    vector<int> h(n);
    int maxv = 0;
    for (int i = 0; i < n; i++) {
        cin >> h[i];
        maxv = max(maxv, h[i]);
    }

    h.pb(0);

    int ans = 0;
    REP(i, maxv){
        ans += count_group(h);
        for (auto& v : h) {
            if(v != 0){
                v--;
            }
        }
    }
    pr(ans);
}