#include <bits/stdc++.h>
#include <vector>
using namespace std;
typedef pair<int, int> intint;

class dfs
{
private:
    int n_;
    vector<int> l_;
    vector<int> length_list_; ///最大要素数(2^16個)
    int a_, b_ , c_;

    int calc(vector<int> v){
        int res = 0;
        int a = 0, b = 0, c = 0;
        for (int i = 0; i < n_; i++) {
            switch(v[i]){
                case 0:
                    res += (a != 0) ? 10 : 0;
                    a += l_[i];
                    break;
                case 1:
                    res += (b != 0) ? 10 : 0;
                    b += l_[i];
                    break;
                case 2:
                    res += (c != 0) ? 10 : 0;
                    c += l_[i];
                    break;
            }
        }
        if(a == 0 || b == 0 || c == 0){
            res += 1000;
        }
        res += std::abs(a - a_) + std::abs(b - b_) + std::abs(c - c_);
        return res;
    }

public:
    dfs(int n, vector<int> l, int a, int b, int c) : n_(n), l_(l), a_(a), b_(b), c_(c) {
    }

    void create(int depth, vector<int> v){
        if(depth == n_) {
            length_list_.push_back(calc(v));
            return;
        }
        for(int i = 0; i < 4; i++)
        {
            v[depth] = i;
            create(depth + 1, v);
        }
    }

    int search(int total){
        int min = 10000000;
        for(auto x : length_list_){
            if(x < min)
                min = x;
        }
        return min;
    }
};

int main(void)
{
    int n, a, b, c;
    cin >> n >> a >> b >> c;

    vector<int> l(n);
    for (int i = 0; i < n; i++) {
        cin >> l[i];
    }
    
    dfs df(n, l, a, b ,c);
    vector<int> v(n, 0);
    df.create(0, v);
    cout << df.search(a + b + c) << endl;
}