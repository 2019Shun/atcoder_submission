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

struct point{
    point(int x = 0, int y = 0) : x(x), y(y){}
    int x; 
    int y;

    // 自分自身との距離を計算
    int calc_distance(point p){
        return abs(x - p.x) + abs(y - p.y);
    }

    // 自分自身からpまでのパスの文字列を形成(UDLRのみ)
    string create_path(point p, bool pick_up=false){
        string ret;
        if(p.x > x) ret += string(abs(p.x-x), 'D');
        if(p.x < x) ret += string(abs(p.x-x), 'U');
        if(p.y > y) ret += string(abs(p.y-y), 'R');
        if(p.y < y) ret += string(abs(p.y-y), 'L');
        if(pick_up) return ret + 'I';
        else return ret;
    }
};
typedef struct point point;

int main(void)
{
    vector<point> p(100);
    REP(i, 100){
        cin >> p[i].x >> p[i].y;
    }

    // 表作成
    vector<vector<int>> table(20, vector<int>(20, -1));
    REP(i, 100){
        table[p[i].x][p[i].y] = i;
    }

    point now;
    string ans;
    REP(i, 100){
        if(i == 99 || now.calc_distance(p[i]) <= now.calc_distance(p[i+1])){
            // 次のカードの方が近いので普通にとりにいく
            ans += now.create_path(p[i], true);
            now = p[i];
        }else{
            // 次の次のカードをとってから
            ans += now.create_path(p[i+1], true);
            now = p[i+1];

            // 次のカードの一番近いところにおいてカード情報を更新し，
            point next;
            int max_distance = 10000000;
            REP(x, 20){
                REP(y, 20){
                    if(table[x][y] < i){
                        // (x,y)においた場合について各距離を計算
                        point tmp(x, y);
                        int dist1 = tmp.calc_distance(p[i]);
                        int dist2 = 0;
                        if(i < 98){
                            dist2 = tmp.calc_distance(p[i+2]);
                        }
                        if(chmin(max_distance, dist1+dist2)){
                            next = tmp;
                        }
                    }
                }
            }
            ans += now.create_path(next);
            ans += 'O';
            now = next;
            p[i+1] = next;

            // 次のカードを取りにいく
            ans += now.create_path(p[i], true);
            now = p[i];
        }
    }

    pr(ans);
}