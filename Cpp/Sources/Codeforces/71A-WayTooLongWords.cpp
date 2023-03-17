/* https://codeforces.com/problemset/problem/71/A */
#include <iostream>
#include <vector>
using namespace std;

int main(void) {
    int n = 0;
    cin >> n;
    string temp = "";
    for(int i = 0; i < n; ++i) {
        cin >> temp;
        if(temp.size() > 10) {
            cout << *temp.begin() + to_string(temp.size() - 2) + *(temp.end() - 1) << endl;
            continue;
        }
        cout << temp << endl;
    }
    return 0;
}