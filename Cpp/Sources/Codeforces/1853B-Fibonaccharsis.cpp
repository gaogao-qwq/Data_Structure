#include "iostream"

using namespace std;

int main() {
    int t = 0, n = 0, k = 0;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        cin >> n >> k;
        int cnt = 0;
        for (int l = n; l > 0; --l) {
            int idx = 0, curr = n - l, prev = l;
            bool flag = true;
            while (idx < k - 2) {
                if (curr > prev) {
                    flag = false;
                    break;
                }
                int tmp = curr;
                curr = prev - curr, prev = tmp, ++idx;
            }
            if (flag) ++cnt;
        }
        cout << cnt << endl;
    }
}