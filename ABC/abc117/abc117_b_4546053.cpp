#include <bits/stdc++.h>
#include <vector>
#define PI 3.14159265358979323846
#define MAXINF 1e18L
#define MININF -1e18L
#define REP(i, n) for(int i=0;i<int(n);++i)
#define RREP(i, n) for(int i=int(n)-1;i>=0;--i)
#define ALL(v) v.begin(),v.end()
using namespace std;
typedef long long ll;
typedef pair<int, int> intint;

int main(void)
{
    int n;
    cin >> n;
    vector<int> l(n);
    for (int i = 0; i < n; i++) {
        cin >> l[i];
    }
    sort(ALL(l));
    int sum = 0;
    REP(i, n-1){
        sum += l[i];
    }

    if(sum <= l[n-1])
        cout << "No";
    else
        cout << "Yes";
}