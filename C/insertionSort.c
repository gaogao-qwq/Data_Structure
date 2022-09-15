#include <stdio.h>

void swap(int *_x, int *_y) {
    int temp = *_x;
    *_x = *_y;
    *_y = temp;
}

void sort(int _arr[], int _len) {
    for (int i = 0; i < _len; i++) {
        // 寻找元素 _arr[i] 合适的插入位置。
        for (int j = i; j > 0; j--) {
            if (_arr[j] < _arr[j - 1]) {
                swap(&(_arr[j]), &(_arr[j - 1]));
            }
            else {
                break;
            }
        }
    }
}

int main(int argc, char **argv) {
    int arr[5] = {54, 12, 65, 45, 11};
    // 别想着把数组传入函数后还能用 sizeof() 获取数组长度，因为传入的实际上是指向数组头部的指针。
    int len = sizeof(arr) / sizeof(arr[0]);
    sort(arr, len);
    for (int i = 0; i < len; i++)
    {
        printf("%d ", arr[i]);
    } 
    return 0;
}