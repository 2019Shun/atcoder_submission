#include <bits/stdc++.h>
using namespace std;
template<class A>void pr(A a){cout << (a) << endl;}
int main(void)
{
    int a,b,c;
    cin >> a >> b >> c;
    if(a==b&&b==c)pr('1');
    else if(a==b||b==c||c==a)pr('2');
    else pr('3');
}