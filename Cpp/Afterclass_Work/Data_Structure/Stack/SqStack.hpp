/* 顺序栈 */
#ifndef STACK_SQSTACK_HPP
#define STACK_SQSTACK_HPP

#include<vector>
#include<stdexcept>
using namespace std;

// 手撕 STL stack 模板
template <typename T>
// 模板类定义
class SqStack {
private:
    // 因为是顺序栈，所以用了vector容器（其实数组也行，但数组写模板太痛苦了）
    vector<T> elems;
public:
    // 入栈
    void push(T const&);
    // 出栈
    void pop();
    // 返回栈顶元素
    T top() const;
    // 检查栈是否为空
    bool empty() const {
        return elems.empty();
    }
};

template <typename T>
void SqStack<T>::push(T const &elem) {
    elems.push_back(elem);
}

template <typename T>
void SqStack<T>::pop() {
    // 若栈为空，抛出 out_of_range 异常
    if(elems.empty()) {
        throw out_of_range("SqStack<>::pop():empty stack");
    }
    elems.pop_back();
}

template <typename T>
T SqStack<T>::top() const {
    // 若栈为空，抛出 out_of_range 异常
    if(elems.empty()) {
        throw out_of_range("SqStack<>::top():empty stack");
    }
    return elems.back();
}

#endif //STACK_SQSTACK_HPP