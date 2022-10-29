/* https://leetcode.cn/problems/sum-of-subarray-minimums/ */
#include "LC.h"

// 别挣扎了，超时了，去写单调栈啦
// 暴力 dp 时空复杂度 O(n2)
class Solution1 {
public:
    int sumSubarrayMins(vector<int>& arr) {
        vector<vector<int>> dp(arr.size(), vector<int>(arr.size()));
        long long sum = 0;
        // 构建 dp 数组
        for (int i = 0; i < arr.size(); ++i) {
            int j = i;
            dp[i][j] = arr[j];
            sum = (sum + dp[i][j] >= 1e9 + 7) ? sum % MOD : sum; 
            sum = (sum + dp[i][j]) % MOD;
            for (++j; j < arr.size(); ++j) {
                if (arr[j] == 1) {
                    sum += (dp[0].size() - j);
                    break;
                }
                dp[i][j] = min(dp[i][j - 1], arr[j]);
                sum = (sum + dp[i][j] >= 1e9 + 7) ? sum % MOD : sum; 
            }
        }
        return sum;
    }
private:
    const int MOD = 1e9 + 7;
};

// dp 单调栈 贡献法 时间复杂度 O(n) 空间复杂度 O(n2)
class Solution2 {
public:
    int sumSubarrayMins(vector<int> &arr) {
        int n = arr.size();
        // 左边界 left[i] 为左侧严格小于 arr[i] 的最近元素位置（不存在时为 -1）
        vector<int> left(n, -1);
        stack<int> stk;
        for (int i = 0; i < n; ++i) {
            while (!stk.empty() && arr[stk.top()] >= arr[i]) {
                stk.pop(); // 移除无用数据
            }
            if (!stk.empty()) left[i] = stk.top();
            stk.push(i);
        }

        // 右边界 right[i] 为右侧小于等于 arr[i] 的最近元素位置（不存在时为 n）
        vector<int> right(n, n);
        while (!stk.empty()) stk.pop();
        for (int i = n - 1; i >= 0; --i) {
            while (!stk.empty() && arr[stk.top()] > arr[i]) {
                stk.pop(); // 移除无用数据
            }
            if (!stk.empty()) right[i] = stk.top();
            stk.push(i);
        }

        long ans = 0;
        for (int i = 0; i < n; ++i) {
            ans += (long) arr[i] * (i - left[i]) * (right[i] - i); // 累加贡献
        }
        return ans % MOD;
    }
private:
    const int MOD = 1e9 + 7;
};

int main() {
    Solution1 s1;
    Solution2 s2;
    vector<int> arr{3,1,2,4};
    cout << s1.sumSubarrayMins(arr) << endl;
    cout << s2.sumSubarrayMins(arr) << endl;
    return 0;
}