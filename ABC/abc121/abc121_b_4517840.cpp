#include <bits/stdc++.h>
#include <vector>
#define PI 3.14159265358979323846
#define MAXINF 1e18L
#define MININF -1e18L
using namespace std;
typedef long long ll;
typedef pair<int, int> intint;

int main(void)
{
    int n, m, c;
    cin >> n >> m >> c;

    vector<int> b(m);
    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }   

    int ans = 0;
    for (int i = 0; i < n; i++) {
        vector<int> a(m);
        int tmp = 0;
        for (int j = 0; j < m; j++) {
            int a;
            cin >> a;
            tmp += a * b[j];
        }
        tmp += c;
        if(tmp > 0) ans++;
    }
    cout << ans;
}