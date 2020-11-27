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
    if(a == 25){
        cout << "Christmas";
    }else if(a == 24){
        cout << "Christmas Eve";
    }else if(a == 23){
        cout << "Christmas Eve Eve";
    }else if(a == 22){
        cout << "Christmas Eve Eve Eve";
    }
    cout << endl;
}