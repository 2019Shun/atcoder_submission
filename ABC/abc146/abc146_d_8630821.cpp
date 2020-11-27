#pragma GCC optimize("Ofast")
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

pii mpair[100010];

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N;
    cin >> N;
    vector<vector<int>> m(N);
    // vector<pii> mpair(N-1);
    map<pii, int> mmap;
    REP(i, N-1) {
        int a,b;
        cin>> a >> b;
        // scanf("%d %d", &a, &b);
        a--;b--;
        m[a].pb(b);
        m[b].pb(a);
        mpair[i] = pii(a,b);
        // mmap[mpair[i]] = -1;
    }

    queue<pii> q;
    q.push(pii(0,N));
    vector<int> ok(N+1);
    while(!q.empty()){
        auto f = q.front();q.pop();
        fill(ALL(ok), 0);
        ok[f.se] = 1;
        for(auto &&c : m[f.fi]){
            pii pc = (f.fi<c?pii(f.fi,c):pii(c,f.fi));

            if(mmap.find(pc) != mmap.end())
                continue;

            int id = 1;
            while(ok[id])
                id++;
            ok[id] = 1;
            mmap[pc] = id;
            q.push(pii(c,id));
        
            // auto &mmapit = mmap[pc];
            // if(mmapit == -1){
            //     while(ok[id])
            //         id++;
            //     ok[id] = 1;
            //     mmapit = id;
            //     q.push(pii(c,id));
            // }
            // if(mmap[pc] == -1){
            //     while(ok[id])
            //         id++;
            //     ok[id] = 1;
            //     mmap[pc] = id;
            //     q.push(pii(c,id));
            // }
        }
    }

    int ans = 0;
    for(auto && i : mmap){
        ans = max(ans, i.se);
    }

    pr(ans);
    REP(i, N-1){
        pr(mmap[mpair[i]]);
        // printf("%d\n", mmap[mpair[i]]);
    }
}