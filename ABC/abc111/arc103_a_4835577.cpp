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
#define RSORT(v) sort(ALL(v), greater<int>())
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

vector<pii> v1(100001);
vector<pii> v2(100001);

int main(void)
{
    int n;
    cin >> n;
    REP(i, n/2){
        int a,b;
        cin >> a >> b;
        v1[a].first++;
        v1[a].second = a;
        v2[b].first++;
        v2[b].second = b;
    }
    
    SORT(v1);
    SORT(v2);

    int ans = 0;
    if(v1[v1.size()-1].second != v2[v2.size()-1].second){
        for (int i = v1.size()-2; i > 0; i--) {
            ans += v1[i].first + v2[i].first;
        }
    }else if(v1[v1.size()-2].first > v2[v2.size()-2].first){
        for (int i = v1.size()-2; i > 0; i--) {
            ans += v1[i].first + v2[i].first;
        }
        ans -= v1[v1.size()-2].first;
        ans += v1[v1.size()-1].first;
    }else{
        for (int i = v1.size()-2; i > 0; i--) {
            ans += v1[i].first + v2[i].first;
        }
        ans -= v2[v2.size()-2].first;
        ans += v2[v2.size()-1].first; 
    }

    pr(ans);
}