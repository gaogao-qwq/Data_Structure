/* https://leetcode.cn/problems/defuse-the-bomb/ */
// 滑动窗口
#include "LC.h"

vector<int> decrypt(vector<int>& code, int k) {
    int n = code.size();
    vector<int> ans(n);
    if(k == 0) {
        return ans;
    }
    code.resize(n * 2);
    copy(code.begin(), code.begin() + n, code.begin() + n);
    int left = k > 0 ? 1 : n + k;
    int right = k > 0 ? k : n - 1;
    int w = 0;
    for(int i = left; i <= right; ++i) {
        w += code[i];
    }
    for(int i = 0; i < n; i++) {
        ans[i] = w;
        w -= code[left];
        w += code[right + 1];
        ++left;
        ++right;
    }
    return ans;
}

int main() {
    vector<int> code{5,7,1,4};
    code = decrypt(code, 3);
    return 0;
}