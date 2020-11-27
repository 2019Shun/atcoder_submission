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
    int n,m;
    cin >> n >> m;

    vector<int> cnt(m,0);
    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;
        for (int j = 0; j < k; j++) {
            int num;
            cin >> num;
            cnt[num-1]++;
        }
    }   

    int ans = 0;
    for (int i = 0; i < m; i++) {
        if(cnt[i] == n){
            ans++;
        }
    }

    cout << ans << endl;
    
}