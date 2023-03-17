#include <iostream>
using namespace std;

int main() {
    int a = 0, b = 0, years = 0;
    cin >> a >> b;
    while(a <= b) {
        ++years;
        a *= 3;
        b *= 2;
    }
    cout << years;
    return 0;
}