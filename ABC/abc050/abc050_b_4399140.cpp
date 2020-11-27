#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n, m;
    cin >> n;
    vector<int> ti(n,0);
    for(int i = 0; i < n; i++){
        cin >> ti[i];
    }

    cin >> m;
    vector<int> pi(m);
    vector<int> xi(m);
    for(int i = 0; i < m; i++){
        cin >> pi[i] >> xi[i];
    }

    for(int i = 0; i < m; i++){
        int r = 0;
        for(int j = 0; j < n; j++){
            if(j + 1 == pi[i]){
                r += xi[i];
            }else{
                r += ti[j];
            }
        }
        cout << r << endl;
    }
}