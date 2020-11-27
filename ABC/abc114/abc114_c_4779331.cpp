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

int solve(ll n){
    int flag = 0;
    while (n) {
        switch (n%10) {
            case 7:
                flag |= 0b0001;
                break;
            case 5:
                flag |= 0b0010;
                break;
            case 3:
                flag |= 0b0100;
                break;

            break;

            default:
                return 0;
            break;
        }
        n /= 10;
    }
    if(flag == 0b0111) return 1;
    else return 0;
}

int dfs(ll s, ll n){
    if(s > n) return 0;
    return solve(s) + dfs(s*10 + 7, n) + dfs(s*10 + 5, n) + dfs(s*10 + 3, n);
}

int main(void)
{
    ll n;
    cin >> n;

    pr(dfs(0,n));
}