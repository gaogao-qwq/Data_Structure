#include <bits/stdc++.h>
using namespace std;

int maxArraySum(int *arr, int n) {
    int prev = 0, curr = 0, ans = INT32_MIN;
    for (int i = 0; i < n; ++i) {
        if (i < 1)
            curr = arr[i];
        else
            curr = max(prev + arr[i], arr[i]);
        ans = max(ans, curr);
        prev = curr;
    }
    return ans;
}

int main() {
    int n = 0, ans = INT32_MIN;
    scanf("%d", &n);
    int mat[n][n] = {};
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            scanf("%d", &mat[i][j]);
        }
    }
    for (int i = 0; i < n; ++i) {
        int currLn[n] = {};
        for (int j = i; j < n; ++j) {
            for (int k = 0; k < n; ++k) {
                currLn[k] += mat[j][k];
            }
            ans = max(ans, maxArraySum(currLn, n));
        }
    }
    printf("%d", ans);
    return 0;
}