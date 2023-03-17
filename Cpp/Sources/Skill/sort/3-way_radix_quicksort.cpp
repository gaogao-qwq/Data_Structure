#include <bits/stdc++.h>
using namespace std;

template <typename T>
void quick_sort(T arr[], const int len) {
    if (len <= 1) return;
    // 随机选择基准（pivot）
    const T pivot = arr[rand() % len];
    // i：当前操作的元素
    // j：第一个等于 pivot 的元素
    // k：第一个大于 pivot 的元素
    int i = 0, j = 0, k = len;
    // 完成一趟三路快排，将序列分为：
    // 小于 pivot 的元素｜ 等于 pivot 的元素 ｜ 大于 pivot 的元素
    while (i < k) {
        if (arr[i] < pivot)
            swap(arr[i++], arr[j++]);
        else if (pivot < arr[i])
            swap(arr[i], arr[--k]);
        else
            i++;
    }
    // 递归完成对于两个子序列的快速排序
    quick_sort(arr, j);
    quick_sort(arr + k, len - k);
}

int main() {
    int arr[10] = {456, 654, 1, 65, 45, 12, 32, 156, 94, 520};
    quick_sort(arr, 10);
    for(auto i : arr) {
        cout << i << " ";
    }
    return 0;
}