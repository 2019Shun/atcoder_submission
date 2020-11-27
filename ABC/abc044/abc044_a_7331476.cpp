#include <bits/stdc++.h>
using namespace std;
int main(void)
{
    int n, k, x, y;
    cin >> n >> k >> x >> y;
    if(n <= k) cout << x * n << endl;
    else cout << k * x + (n - k) * y << endl;
}