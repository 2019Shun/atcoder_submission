#include <bits/stdc++.h>
#include <vector>
#define PI 3.14159265358979323846
#define MAXINF 1e18L
#define MININF -1e18L
using namespace std;
typedef long long ll;
typedef pair<int, int> intint;

class drink
{
private:
public:
    ll a;
    ll b;
    drink(ll a, ll b) : a(a), b(b){ }

    bool operator==(drink d) {
        return a == d.a;
    }
    bool operator<(drink d) {
        return a < d.a;
    }
    bool operator>(drink d) {
        return a > d.a;
    }
};
int main(void)
{
    int n, m;
    cin >> n >> m;

    vector<drink> d;
    for (int i = 0; i < n; i++) {
        ll a , b;
        cin >> a >> b;
        d.push_back(drink(a, b));
    }

    sort(d.begin(), d.end());

    ll ans = 0;
    ll count = 0;
    for (drink dr : d) {
        for (int j = 0; j < dr.b; j++) {
            if(count++ >= m){
                goto result;
            }
            ans += dr.a;
        }
    }
    result:
    cout << ans;
}