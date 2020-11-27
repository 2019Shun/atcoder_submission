#include <bits/stdc++.h>
#include <vector>
#include <numeric>
#define PI 3.14159265358979323846
#define MAXINF 1e18L
#define MININF -1e18L
#define REP(i, n) for(int i=0;i<int(n);++i)
#define RREP(i, n) for(int i=int(n)-1;i>=0;--i)
#define ALL(v) v.begin(),v.end()
#define DEBUG(x) cerr<<#x<<": "<<x<<endl;
#define DEBUG_VEC(v) cerr<<#v<<":";for(int i=0;i<v.size();i++) cerr<<" "<<v[i]; cerr<<endl
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> intint;

int main(void)
{
    int a;
    cin >> a;
    vector<int> p(a);
    for (int i = 0; i < a; i++) {
        cin >> p[i];
    }
    sort(ALL(p));

    int ans = 0;
    for (int i = 0; i < a - 1; i++) {
        ans += p[i];
    }
    ans += p[a - 1] / 2;

    cout << ans << endl;
}