#include <bits/stdc++.h>
#include "SqQueue.hpp"
using namespace std;

int main() {
    // 初始化长度为10的整型队列
    sqQueue<int> que(10);
    // 入队
    que.push(1);
    que.push(1);
    que.push(4);
    que.push(5);
    que.push(1);
    que.push(4);
    //打印
    que.print();
    // 获取大小
    cout << "size:" << que.size() << endl;
    // 获取队头元素
    cout << "front:" << que.front() << endl;
    // 获取队尾元素
    cout << "back:" << que.back() << endl;
    // 出队
    que.pop(); que.pop(); que.pop(); que.pop();
    cout << "front:" << que.front() << endl;
    cout << "back:" << que.back() << endl;
    cout << "size:" << que.size() << endl;
    que.pop(); que.pop();
    // 判断是否为空队列
    cout << boolalpha << que.empty();
    return 0;
}