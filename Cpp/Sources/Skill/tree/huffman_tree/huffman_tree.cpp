#include <bits/stdc++.h>
using namespace std;

struct HNode {
    int weight;
    HNode *left, *right;
    HNode(int w, HNode *l, HNode *r) : weight(w), left(l), right(r) {}
};

HNode *createHuffmanTree(int arr[], int n) {
    HNode *forest[n];
    HNode *root = nullptr;
    // 将所有点存入森林
    for (int i = 0; i < n; ++i) {
        auto tmp = new HNode(arr[i], nullptr, nullptr);
        forest[i] = tmp;
    }
    // n-1 次循环建哈夫曼树
    for (int i = 1; i < n; ++i) {
        // minn 为最小值树根下标，minnsub 为次小值树根下标
        int minn = -1, minnSub;
        for (int j = 0; j < n; ++j) {
            if (forest[j] != nullptr && minn == -1) {
                minn = j;
                continue;
            }
            if (forest[j] != nullptr) {
                minnSub = j;
                break;
            }
        }
        // 根据 minn 与 minnSub 赋值
        for (int j = minnSub; j < n; ++j) {
            if (forest[j] != nullptr) {
                if (forest[j]->weight < forest[minn]->weight)
                    minnSub = minn, minn = j;
                else if (forest[j]->weight < forest[minnSub]->weight)
                    minnSub = j;
            }
        }
        // 建新树
        root = new HNode(forest[minn]->weight + forest[minnSub]->weight, forest[minn], forest[minnSub]);
        // 指向新树的指针赋给 minn 位置
        forest[minn] = root;
        // minnSub 位置为空
        forest[minnSub] = nullptr;
    }

    return root;
}

int main() {
    int arr[10] = {1,2,3,4,5,6,7,8,9,10};
    auto root = createHuffmanTree(arr, 10);
    return 0;
}