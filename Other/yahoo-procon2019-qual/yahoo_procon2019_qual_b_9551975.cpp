#include <bits/stdc++.h>
using namespace std;
#define ALL(a) (a).begin(),(a).end()
#define rALL(a) (a).rbegin(),(a).rend()
typedef pair<int, int> Pint;
typedef pair<int64_t, int64_t> Pll;
 
 
int main() {
    vector<int> A(4);
    for (int i = 0; i < 6; i++){
        int a;
        cin >> a;
        A.at(a - 1)++;
    }
    sort(ALL(A));
    if (A.at(0) == 1 && A.at(1) == 1 && A.at(2) == 2 && A.at(3) == 2){
        cout << "YES" << endl;
    } 
    else {
        cout << "NO" << endl;
    }
}