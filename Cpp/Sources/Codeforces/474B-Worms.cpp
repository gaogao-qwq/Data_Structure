#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

int main() {
    int n = 0, m = 0;
    cin >> n;
    vector<int> a(n, 0);
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    cin >> m;
    vector<int> q(m, 0);
    for(int i = 0; i < m; ++i) {
        cin >> q[i];
    }

    for(int i = 0; i < q.size(); ++i) {
        int sum = accumulate(a.begin(), a.begin() + (n / 2) + 1, 0);
        if(q[i] == sum) {
            cout << n / 2 + 1 << endl;
            break;
        }
        if(q[i] < sum) {
            for(int j = n / 2; j >= 0; --j) {
                sum -= a[j];
                if(q[i] > sum) {
                    cout << j + 1 << endl;
                    break;
                }
            }
        } else {
            for(int j = n / 2; j < a.size() - 1; ++j) {
                sum += a[j + 1];
                if(q[i] <= sum) {
                    cout << j + 2 << endl;
                    break;
                }
            }
        }
        
    }
    return 0;
}