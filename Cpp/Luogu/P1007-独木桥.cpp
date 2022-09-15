/* https://www.luogu.com.cn/problem/P1007 */
#include <iostream>
#include <vector>
using namespace std;

int main(void) {
    int l, n = 0;
    cin >> l;
    vector<int> bridge(l, 0);
    cin >> n;
    if(!n) {
        cout << "0 0" << endl;
        return 0;
    }
    if(n == 1) {
        int temp = 0;
        cin >> temp;
        cout << min(l - temp + 1, temp) << " " << max(l - temp + 1, temp);
        return 0;
    }
    for(int i = 0; i < n; ++i) {
        int temp = 0;
        cin >> temp;
        ++bridge[temp - 1];
    }
    if(l % 2) {
        int mid = l / 2;
        for(int i = mid, j = i; j < bridge.size() && i >= 0; --i, ++j) {
            if(bridge[i]) {
                cout << i + 1 << " ";
                break;
            }
            if(bridge[j]) {
                cout << l - j << " ";
                break;
            }
        }
    } else {
        int mid = l / 2;
        for(int j = mid, i = j - 1; j < bridge.size() && i >= 0; --i, ++j) {
            if(bridge[i]) {
                cout << i + 1 << " ";
                break;
            }
            if(bridge[j]) {
                cout << l - j << " ";
                break;
            }
        }
    }
    for(int i = 0, j = bridge.size() - 1; i <= j; ++i, --j) {
        if(bridge[i]) {
            cout << l - i - 1;
            break;
        }
        if(bridge[j]) {
            cout << j + 1;
            break;
        }
    }
    return 0;
}