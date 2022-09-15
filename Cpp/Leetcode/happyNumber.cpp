#include <iostream>
#include <cmath>
using namespace std;

int squareSum(int n) {
        int ret = 0;
        while(n > 0) {
            ret += pow(n % 10, 2);
            n /= 10;
        }
        return ret;
    }

int main(void) {
    cout << squareSum(19) << endl;
    return 0;
}
