#include "LC.h"

class Node {
public:
    int key;
    int val;
    Node *prev;
    Node *next;

    explicit Node(int key, int val) : key(key), val(val), prev(nullptr), next(nullptr) {}

    Node(int key, int val, Node *prev, Node *next) : key(key), val(val), prev(prev), next(next) {}

    ~Node() { free(this); }
};

class List {
public:
    Node *dummyHead;
    Node *dummyTail;
    int size;

    List() {
        dummyHead = new Node(0, 0, nullptr, nullptr);
        dummyTail = new Node(0, 0, nullptr, nullptr);
        dummyHead->next = dummyTail;
        dummyTail->prev = dummyHead;
        size = 0;
    }

    Node *tail() {
        return dummyTail->prev;
    }

    void push_front(Node *node) {
        Node *head = dummyHead->next;
        node->next = head, node->prev = dummyHead;
        dummyHead->next = node, head->prev = node;
        ++size;
    }

    void remove(Node *node) {
        Node *prev = node->prev;
        Node *next = node->next;
        prev->next = next, next->prev = prev;
        --size;
    }

    void pop_back() {
        Node *tmp = dummyTail->prev;
        tmp->prev->next = dummyTail;
        dummyTail->prev = tmp->prev;
        --size;
    }
};

class LRUCache {
public:
    explicit LRUCache(int capacity) {
        this->capacity = capacity;
        this->cache = std::move(unordered_map<int, Node *>(capacity));
        this->list = new List();
    }

    int get(int key) {
        if (!cache.contains(key)) return -1;
        Node *node = cache[key];
        list->remove(node);
        list->push_front(node);
        return cache[key]->val;
    }

    void put(int key, int value) {
        if (cache.contains(key)) {
            list->remove(cache[key]);
        }
        Node *node = new Node(key, value);
        cache[key] = node;
        list->push_front(node);
        if (list->size > capacity) {
            cache.erase(list->tail()->key);
            list->pop_back();
        }
    }

private:
    int capacity;
    unordered_map<int, Node *> cache;
    List *list;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

int main() {
    auto *obj = new LRUCache(1);
    obj->put(2, 1);
    cout << obj->get(2) << endl;
    obj->put(3, 2);
    cout << obj->get(2) << endl;
    cout << obj->get(3) << endl;
}