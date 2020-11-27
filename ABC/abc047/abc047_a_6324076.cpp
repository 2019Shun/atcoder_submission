#include <bits/stdc++.h>
#define Yes(n) cout<<((n)?"Yes":"No")<<endl
using namespace std;
template<class A>void pr(A a){cout << (a) << endl;}
int main(void)
{
    int a,b,c;
    cin >> a >> b >> c;
    Yes((a+b)==c||(a+c)==b||(b+c)==a);
}