#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    int a, b;
    cin >> a >> b;
    if(b % a == 0){
        cout << a + b;
    }else{
        cout << b - a;
    }
}
 