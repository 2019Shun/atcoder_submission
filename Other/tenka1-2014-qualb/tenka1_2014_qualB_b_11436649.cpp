#include <iostream>
#include <string>
#include <vector>
using namespace std;

int N;
string S;
vector<string> T;
vector<int> memo;
int f(int i){
    if(i < 0)return 0;
    if(i == 0)return 1;
    if(memo[i] != -1)return memo[i];
    int ret = 0;
    for(const string& t : T)
        if(i >= t.length() && S.compare(i - t.length(), t.length(), t) == 0)
            ret = (ret + f(i - t.length())) % 1000000007;
    return memo[i] = ret;
}

int main(){
    cin >> N;
    cin >> S;
    T.resize(N);
    for(int i=0; i<N; ++i)cin >> T[i];
    memo = vector<int>(S.length() + 1, -1);
    cout << f(S.length()) << endl;
    return 0;
}