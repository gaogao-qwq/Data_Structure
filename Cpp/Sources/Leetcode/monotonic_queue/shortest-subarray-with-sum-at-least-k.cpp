/* https://leetcode.cn/problems/shortest-subarray-with-sum-at-least-k/ */
#include "LC.h"

// 初看这道题似乎可以用滑动窗口解决，实则不然
// 这题由于数据范围包含了负数，所以实际上不能保证数据的单调性，故不能使用滑动窗口

// 暴力O(n3)，超时
class Solution1 {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        if (nums.size() == 1) return (nums[0] == k) ? k : -1;
        int minLen = nums.size() + 1;
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = i; j < nums.size(); ++j) {
                int sum = 0;
                for (int k = i; k <= j; ++k) {
                    sum += nums[k];
                }
                if (sum >= k && j - i + 1 < minLen) {
                    minLen = j - i + 1;
                }
            }
        }
        return (minLen == nums.size() + 1) ? -1 : minLen;
    }
};

// 暴力 + dp，dp 负责降低最内层循环求和步骤的时间复杂度开销
// dp[i] 代表前i个元素的和 dp[i + 1] = dp[i] + nums[i];
// 时间复杂度 O(n2)，然而会超时
class Solution2 {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        // 特判
        if (nums.size() == 1) return (nums[0] == k) ? k : -1;
        // 构建 dp 数组
        int minLen = nums.size() + 1;
        vector<int> dp(nums.size() + 1);
        dp[0] = 0;
        for (int i = 0; i < nums.size(); ++i) {
            dp[i + 1] = dp[i] + nums[i];
        }

        for (int i = 0; i <= nums.size(); ++i) {
            for (int j = i + 1; j < nums.size() + 1; ++j) {
                if (dp[j] - dp[i] >= k) {
                    minLen = (j - i < minLen) ? (j - i) : minLen;
                }
            }
        }
        return (minLen == nums.size() + 1) ? -1 : minLen;
    }
};

// 单调队列，时间复杂度 O(n)
// 优化1：
// 当 dp[j] - dp[i] >= k 时，dp[i - 1]（若存在）可以直接弹出
// 因为题目要求的是最短连续子数组
// 优化2：
// 观察规律可以发现对于任意 dp[j] <= dp[i] 且后续有任意数 x - dp[j] >= k 的，
// 也必然有 x - dp[j] >= k
class Solution3 {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        // 特判
        if (nums.size() == 1) return (nums[0] == k) ? k : -1;
        // 构建 dp 数组
        int minLen = nums.size() + 1;
        vector<long> dp(nums.size() + 1);
        dp[0] = 0;
        for (int i = 0; i < nums.size(); ++i) {
            dp[i + 1] = dp[i] + nums[i];
        }
        // 维护一个单调队列
        deque<int> deq;
        for (int i = 0; i < nums.size() + 1; ++i) {
            // 优化2
            while (!deq.empty() && dp[i] <= dp[deq.back()]) {
                deq.pop_back();
            }
            // 优化1
            while (!deq.empty() && dp[i] - dp[deq.front()] >= k) {
                int newLen = i - deq.front();
                deq.pop_front();
                if (newLen < minLen) {
                    minLen = newLen;
                }
            }
            deq.push_back(i);
        }
        return (minLen == nums.size() + 1) ? -1 : minLen;
    }
};

int main() {
    Solution1 s1;
    Solution2 s2;
    Solution3 s3;
    vector<int> nums{48,99,37,4,-31};
    cout << s3.shortestSubarray(nums, 140) << endl;
    return 0;
}