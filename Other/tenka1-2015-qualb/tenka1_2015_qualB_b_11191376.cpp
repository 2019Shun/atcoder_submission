#include <bits/stdc++.h>
#define PI 3.14159265358979323846
#define MAXINF (1e18L)
#define INF (1e9L)
#define EPS (1e-9)
#define MOD ((ll)(1e9+7))
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
template<class T> inline bool chmin(T& a, T b){return a>b ? a=b, true : false;}
template<class T> inline bool chmax(T& a, T b){return a<b ? a=b, true : false;}
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll,ll> pll;

string S;
int cur;

int dfs() {
	
	if(S[cur]!='{') {
		while(S[cur]>='0' && S[cur]<='9') cur++;
		return 2;
	}
	cur++;
	if(S[cur]=='}') return cur++,0; //dict
	
	dfs();
	if(S[cur]==':') { //dict
		cur++;
		dfs();
		while(S[cur]!='}') cur++, dfs(), cur++, dfs();
		cur++;
		return 0;
	}
	else { //set
		while(S[cur]!='}') cur++, dfs();
		cur++;
		return 1;
	}
	
}

int main(void)
{
    cin >> S;
    // int n = tmp_S.length();
    // bool is_int = false;
    // REP(i, n){
    //     if(0 <= tmp_S[i]-'0' && tmp_S[i]-'0' <= 9){
    //         if(is_int){
    //             continue;
    //         }else{
    //             S.pb('I');
    //         }
    //         is_int = true;
    //     }else{
    //         S.pb(tmp_S[i]);
    //         is_int = false;
    //     }
    // }

	if(dfs()==0) cout<<"dict"<<endl;
	else cout<<"set"<<endl;
}