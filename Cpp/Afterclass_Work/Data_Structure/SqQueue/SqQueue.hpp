#ifndef SQ_QUEUE_HPP
#define SQ_QUEUE_HPP

#include <vector>
#include <stdexcept>
using namespace std;

template<typename T>
class sqQueue {
private:
	T *elem;
	int head;
	int tail;
    int maxSize;
public:
    // 构造函数
    sqQueue(int size) : maxSize(size), elem(new T[maxSize]), head(0), tail(0) {}
public:
    bool empty();
    int size();
    void pop();
    void push(T val);
    void print();
    T front();
    T back();
};

template<class T>
bool sqQueue<T>::empty() {
    if (head == tail) return true;
    return false;
}

template<class T>
int sqQueue<T>::size() {
    return (tail - head + maxSize) % maxSize;
}

template<class T>
void sqQueue<T>::pop() {
    if (head == tail) exit(0);
    head = (head + 1) % maxSize;
}

template<class T>
void sqQueue<T>::push(T val) {
    if ((tail + 1) % maxSize == head) exit(-1);
    elem[tail] = val;
    tail = (tail + 1) % maxSize;
}

template<class T>
void sqQueue<T>::print() {
    if (head == tail) exit(0);
    int tmp = head;
    while(tmp != tail) {
        cout << elem[tmp] << " ";
        tmp = (tmp + 1) % maxSize;
    }
    cout << endl;
}

template<class T>
T sqQueue<T>::front() {
    if (head == tail) exit(0);
    return elem[head];
}

template<class T>
T sqQueue<T>::back() {
    if (head == tail) exit(0);
    return elem[tail - 1];
}

#endif // SQ_QUEUE_HPP