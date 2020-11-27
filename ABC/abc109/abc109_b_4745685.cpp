#include <bits/stdc++.h>
#include <vector>
#include <string>
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
    int n;
    cin >> n;
    vector<string> wi(n);
    for (int i = 0; i < n; i++) {
        cin >> wi[i];
    }  

    Rep(i,1,n){
        // if(wi[i-1][wi[i-1].size()-1] != wi[i][0]){
        if(wi[i-1].back() != wi[i].front()){
            pr("No");
            return 0;
        }

        REP(j, i){
            if(wi[i] == wi[j]){
                pr("No");
                return 0;
            }
        }
    }

    pr("Yes");
    return 0;
}