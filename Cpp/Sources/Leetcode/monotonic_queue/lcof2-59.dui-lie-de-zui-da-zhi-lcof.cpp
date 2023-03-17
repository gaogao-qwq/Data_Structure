/* https://leetcode.cn/problems/dui-lie-de-zui-da-zhi-lcof/ */
#include "LC.h"

// 简单单调队列
class MaxQueue {
public:
    MaxQueue() {

    }
    
    int max_value() {
        if (que.empty()) return -1;
        return deq.front();
    }
    
    void push_back(int value) {
        que.push(value);
        while (!deq.empty() && value > deq.back()) {
            deq.pop_back();
        }
        deq.push_back(value);
    }
    
    int pop_front() {
        if (que.empty()) return -1;
        int tmp = que.front();
        que.pop();
        if (tmp == deq.front()) deq.pop_front();
        return tmp;
    }
private:
    deque<int> deq;
    queue<int> que;
};


int main() {
    MaxQueue obj;
    obj.push_back(1);
    obj.push_back(2);
    cout << obj.max_value() << endl;
    cout << obj.pop_front() << endl;
    cout << obj.max_value() << endl;
    return 0;
}