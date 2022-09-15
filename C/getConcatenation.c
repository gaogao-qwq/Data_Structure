/**
 * 给你一个长度为 n 的整数数组 nums。请你构建一个长度为 2n 的答案数组 ans，数组下标 从 0 开始计数，对于所有 0 <= i < n 的 i，满足下述所有要求：
 * ans[i] == nums[i]
 * ans[i + n] == nums[i]
 * 具体而言，ans 由两个 nums 数组串联形成。
 * 返回数组 ans。
 * 
 * - example -
 * 输入：nums = [1,2,1]
 * 输出：[1,2,1,1,2,1]
 * 解释：数组 ans 按下述方式形成：
 * - ans = [nums[0],nums[1],nums[2],nums[0],nums[1],nums[2]]
 * - ans = [1,2,1,1,2,1]
 * 
 */

#include <stdio.h>
#include <stdlib.h>

int* getConcatenation(int *nums, int numsSize, int *returnSize) {
    *returnSize = 2 * numsSize;
    // malloc 一个比原数组大小大一倍的 ans 数组。
    int *ans = (int *)malloc(2 * numsSize * sizeof(int));
    for(int i = 0; i < numsSize; ++i) {
        ans[i] = nums[i];
        ans[numsSize + i] = nums[i];
    }
    return ans;
}

int main(int argc, char **argv) {
    int nums[3] = {1, 2, 1};
    int returnSize;
    getConcatenation(nums, 3, &returnSize);
    int *ans = (int *)malloc(returnSize * sizeof(int));
    ans = getConcatenation(nums, 3, &returnSize);
    for (int i = 0; i < 6; i++) {
        printf("%d", ans[i]);
    }
    return 0;
}