#include <bits/stdc++.h>
#include <string>

using namespace std;

int main(void){
    int N;
    cin >> N;
    double ans = 0;
    for(int i = 0; i < N; i++){
        double x;
        string s;
        cin >> x >> s;
        if(s == "JPY"){
            ans += x;
        }else{
            ans += x * 380000.0;
        }
    }

    cout << ans;
}