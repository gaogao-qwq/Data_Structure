#include <iostream>
#include <cmath>
using namespace std;
int main() {
    int n = 0;
    cin >> n;
    int great(0), pass(0);
    for (int i = 0; i < n; ++i) {
        int tmp = 0;
        cin >> tmp;
        if (tmp >= 85) {
            ++great;
            continue;
        }
        if (tmp >= 60) {
            ++pass;
        }
    }
    cout << round(pass * 100 / (float)n) << "%" << endl;
    cout << round(great * 100 / (float)n) << "%" << endl;
    return 0;
}