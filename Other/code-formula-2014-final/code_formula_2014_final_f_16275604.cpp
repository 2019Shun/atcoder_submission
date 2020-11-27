#include <bits/stdc++.h>
#define PI 3.14159265358979323846
#define MAXINF (1e18L)
#define INF (1e9L)
#define EPS (1e-9)
#define MOD ((ll)(1e9+7))
#define REP(i, n) for(int i=0;i<int(n);++i)
#define REPA(x, v) for(auto&& x:v)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define RREP(i, n) for(int i=int(n)-1;i>=0;--i)
#define ALL(v) v.begin(),v.end()
#define FIND(v,x) (binary_search(ALL(v),(x)))
#define SORT(v) sort(ALL(v))
#define RSORT(v) sort(v.rbegin(),v.rend())
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
template<class T> void pr_vec(vector<T> &v, char ep=' '){int n=v.size();REP(ni,n){cout<<v[ni];if(ni!=n-1)cout<<ep;}cout<<endl;};
template<class T> inline bool chmin(T& a, T b){return a>b ? a=b, true : false;}
template<class T> inline bool chmax(T& a, T b){return a<b ? a=b, true : false;}
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll,ll> pll;

int main(void)
{
int ans[] = {
1 , 1 ,
2 , 4 ,
3 , 9 ,
4 , 16 ,
5 , 25 ,
6 , 36 ,
7 , 49 ,
8 , 64 ,
9 , 81 ,
10 , 100 ,
11 , 121 ,
12 , 144 ,
13 , 169 ,
14 , 196 ,
15 , 225 ,
16 , 256 ,
17 , 289 ,
18 , 324 ,
19 , 361 ,
20 , 400 ,
21 , 441 ,
22 , 484 ,
23 , 529 ,
24 , 576 ,
25 , 625 ,
26 , 676 ,
27 , 729 ,
28 , 784 ,
29 , 841 ,
30 , 900 ,
31 , 961 ,
32 , 1024 ,
33 , 1089 ,
34 , 1156 ,
35 , 1225 ,
36 , 1296 ,
37 , 1369 ,
38 , 1444 ,
52 , 39 ,
62 , 118 ,
69 , 199 ,
75 , 300 ,
81 , 416 ,
86 , 503 ,
90 , 597 ,
94 , 700 ,
99 , 809 ,
103 , 928 ,
108 , 1053 ,
112 , 1188 ,
117 , 1328 ,
128 , 1431 ,
140 , 66 ,
153 , 244 ,
157 , 353 ,
177 , 545 ,
185 , 749 ,
189 , 864 ,
193 , 986 ,
197 , 1116 ,
202 , 1253 ,
220 , 149 ,
229 , 1375 ,
238 , 441 ,
248 , 643 ,
263 , 292 ,
298 , 801 ,
305 , 1046 ,
312 , 1183 ,
326 , 70 ,
334 , 536 ,
352 , 1319 ,
365 , 387 ,
373 , 921 ,
376 , 207 ,
383 , 684 ,
437 , 1107 ,
462 , 1421 ,
474 , 88 ,
478 , 808 ,
480 , 490 ,
493 , 1256 ,
499 , 307 ,
524 , 968 ,
540 , 645 ,
600 , 1121 ,
613 , 179 ,
620 , 1370 ,
633 , 415 ,
645 , 840 ,
704 , 581 ,
732 , 1000 ,
740 , 1233 ,
761 , 284 ,
775 , 95 ,
803 , 740 ,
825 , 1403 ,
847 , 456 ,
889 , 1109 ,
902 , 910 };


REP(i, 100){
    pr(ans[i*2], ans[i*2+1]);
}

}