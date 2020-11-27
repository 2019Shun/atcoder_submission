#include <bits/stdc++.h>
#include <vector>
#include <numeric>
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

struct union_find {
	vector<int> parent; //親の番号を格納する。親だった場合は-(その集合のサイズ)
	union_find(int N) {
		parent = vector<int>(N, -1); //parentの値を-1にする(すべてバラバラ)
	}
	int root(int A) { //Aがどのグループに属しているか調べる
		if (parent[A] < 0) return A;
		return parent[A] = root(parent[A]);
	}
	int size(int A) { //自分のいるグループの頂点数を調べる
		return -parent[root(A)];//親をとってきたい]
	}
	bool connect(int A, int B) { //AとBをくっ付ける．すでにつながっていた場合false
		//AとBを直接つなぐのではなく、root(A)にroot(B)をくっつける
		A = root(A);
		B = root(B);
		if (A == B) return false; //すでにくっついてるからくっ付けない
		if (size(A) < size(B)) swap(A, B); //大小が逆だったらひっくり返しちゃう。
		parent[A] += parent[B]; //Aのサイズを更新する
		parent[B] = A; //Bの親をAに変更する
		return true;
	}
};

int main(void)
{
    int N,M;
    cin >> N >> M;
    vector<int> X(M), Y(M), Z(M);
    union_find uf(N);
    REP(i, M){
        cin >> X[i] >> Y[i] >> Z[i];
        X[i]--;Y[i]--;
        uf.connect(X[i], Y[i]);
    }
    vector<int> ok(N, 0);
    int ans = 0;
    REP(i, N){
        if(uf.parent[i] < 0) ans++;
    }
    pr(ans);
}