#include <bits/stdc++.h>
using namespace std;

int main(void){
    char s[11];
    cin >> s;

    char m[3];
    for(int i = 0; i < 4; i++){
        m[i] = s[i+5];
    }
    m[2] = '\0';

    int mi = atoi(m);

    if(mi > 4){
        cout << "TBD";
    }else{
        cout << "Heisei";
    }
    cout << endl;
}