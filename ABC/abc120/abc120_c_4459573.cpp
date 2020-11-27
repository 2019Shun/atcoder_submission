#include <bits/stdc++.h>
using namespace std;

int main(void){
    string s;
    cin >> s;

    int a = 0, b = 0;
    for(int i = 0; i < (int)s.size(); ++i){
        char ch = s[i];
        if(ch == '0'){
            a++;
        }else{
            b++;
        }
    }
    cout << min(a, b) * 2;
}