/* 链栈 */
#ifndef STACK_LINKEDSTACK_HPP
#define STACK_LINKEDSTACK_HPP

#include<stdexcept>
using namespace std;

template<typename T>
struct LinkedNode{
    T val; // 数据域
    LinkedNode *next; // 指针域
};

template<typename T>
class LinkedStack {
private:
    LinkedNode<T>* _top = nullptr;
    int size = 0;
public:
    // 入栈
    void push(T const&);
    // 出栈
    void pop();
    // 返回栈顶元素
    T top() const;
    // 检查栈是否为空
    bool empty() const {
        return !size;
    }
};

template<typename T>
void LinkedStack<T>::push(const T &val) {
    auto *node = new LinkedNode<T>;
    node->val = val;
    node->next = _top;
    _top = node;
    ++size;
}

template<typename T>
void LinkedStack<T>::pop() {
    // 若栈为空，抛出 out_of_range 异常
    if(!size) {
        throw out_of_range("LinkedStack<>::pop():empty stack");
    }
    LinkedNode<T> *del = _top;
    _top = _top->next;
    delete(del);
    --size;
}

template<typename T>
T LinkedStack<T>::top() const {
    // 若栈为空，抛出 out_of_range 异常
    if(!size) {
        throw out_of_range("LinkedStack<>::top():empty stack");
    }
    return _top->val;
}

#endif //STACK_LINKEDSTACK_HPP