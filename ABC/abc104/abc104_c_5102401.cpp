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
#define fi first
#define se second
using namespace std;
template<class A>void pr(A a){cout << (a) << endl;}
template<class A,class B>void pr(A a,B b){cout << a << " "  ;pr(b);}
template<class A,class B,class C>void pr(A a,B b,C c){cout << a << " " ;pr(b,c);}
template<class A,class B,class C,class D>void pr(A a,B b,C c,D d){cout << a << " " ;pr(b,c,d);}
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;

int main(void)
{
    int d,g;
    cin >> d >> g;
    vector<pii> p;
    REP(i, d){
        int pi,ci;
        cin >> pi >> ci;
        p.pb(make_pair(pi,ci));
    }

    int ans = INF;

    vector<int> v(d);
    iota(ALL(v), 1);
    reverse(ALL(v));
    do{
        int tmp = 0;
        int t_ans = 0;
        for (auto j : v) {
            if(p[j-1].fi * 100 * j + tmp + p[j-1].se >= g){
            }else{
                tmp += (p[j-1].fi * 100 * j + p[j-1].se);
                t_ans += p[j-1].fi;
                continue; 
            }
            bool flag = false;
            bool finish = false;
            REP(k, p[j-1].fi){
                tmp += j*100;
                if(++t_ans >= ans) {
                    finish = true;
                    break;
                }
                if(tmp>=g){
                    flag = true;
                    break;
                }
                
            }
            if(finish) break;
            if(flag){
                ans = min(ans, t_ans);
            }else{
                tmp += p[j-1].se;
                if(tmp>=g) ans = min(ans, t_ans);
            }
        }
    }while(prev_permutation(ALL(v)));
    
    pr(ans);
}