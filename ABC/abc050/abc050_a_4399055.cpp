#include <iostream>
using namespace std;

int main(void){
    int a, b;
    char op;
    
    cin >> a >> op >> b;

    int result;
    if(op == '+'){
        result = a + b;
    }else if(op == '-'){
        result = a - b;
    }

    cout << result;
}