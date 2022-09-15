/* https://codeforces.com/problemset/problem/282/A */
#include <iostream>
using namespace std;

int main(void) {
    string cmd = "";
    int n = 0, x = 0;
    cin >> n;
    for(int i = 0; i < n; ++i) {
        cin >> cmd;
        if(cmd == "X++" || cmd == "++X") ++x;
        else --x;
    }
    cout << x;
    return 0;
}