#include <bits/stdc++.h>
using namespace std;

    int commonFactors(int a, int b) {
        int cnt = 0;
        for(int i = 1; i <= min(a, b); ++i) {
            if(a % i == 0 && b % i == 0) ++cnt;
        }
        return cnt;
    }

int main() {
    cout << commonFactors(25, 30);
    return 0;
}