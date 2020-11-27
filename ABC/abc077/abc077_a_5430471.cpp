#include <bits/stdc++.h>
#define REP(i, n) for(int i=0;i<int(n);++i)
#define Yes(n) cout<<((n)?"YES":"NO")<<endl
using namespace std;
template<class A>void pr(A a){cout << (a) << endl;}
int main(void)
{
	string a,b;
  	cin >> a >> b;
  	Yes(a[0]==b[2]&&a[1]==b[1]&&a[2]==b[0]);
}