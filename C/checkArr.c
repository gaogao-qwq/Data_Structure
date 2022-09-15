#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int cmpfunc(const void *a, const void *b) {
   return (*(int *)a - *(int *)b);
}

bool isSorted(int *nums, int numsSize) {
    int temp[101] = {}, count = 0;
    for(int i = 0; i < numsSize; i++) {
        temp[i] = nums[i];
    }
    qsort(temp, numsSize, sizeof(int), cmpfunc);
    for(int i = 0; i < numsSize; i++) {
        if(temp[i] == nums[i]) {
            count++;
        }
    }
    if(count == numsSize) {
        return true;
    }
    return false;
}

bool check(int *nums, int numsSize){
    int temp[101] = {}, last = 0;
    if(isSorted(nums, numsSize)) {
        return true;
    }
    // 外层循环控制轮转遍历
    for(int i = 0; i < numsSize; i++) {
        // 内层循环控制数组下标遍历
        for(int j = 0; j < numsSize; j++) {
            temp[(j + i) % numsSize] = nums[j];
        }
        if(isSorted(temp, numsSize)) {
        return true;
        }
    }
    return false;
}

int main(int argc, char **argv) {
    int arr[7] = {2, 7, 4, 1, 2, 6, 2};
    bool res = check(arr, 7);
    return 0;
}