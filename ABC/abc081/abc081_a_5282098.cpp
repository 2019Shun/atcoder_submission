#include <bits/stdc++.h>
using namespace std;
int main(void)
{
    int ans=0;
    for (int i = 0; i < 3; i++) {
        char c;cin>>c;
        if(c=='1')ans++;
    }   
    cout << ans << endl;
}