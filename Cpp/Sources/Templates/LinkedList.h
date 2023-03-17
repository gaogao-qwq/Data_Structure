#ifndef DATA_STRUCTURE_LINKEDLIST_H
#define DATA_STRUCTURE_LINKEDLIST_H

#include <memory>
#include <type_traits>

namespace DataStructure {
	template <typename T>
	class ListNode {
	public:
		T val;
		std::shared_ptr<ListNode> next = nullptr;
		std::shared_ptr<ListNode> prev = nullptr;
	public:
		ListNode() = default;
		ListNode(T _val, std::shared_ptr<ListNode> _next, std::shared_ptr<ListNode> _prev) :
				val(_val), next(_next), prev(_prev) {}
	};

	template <typename T>
	class ListIterator {
	public:
		typedef ListIterator<T> iterator;
		typedef T value;
		typedef T &reference;
		std::shared_ptr<ListNode<T>> node;
	public:
		explicit ListIterator() : node(nullptr) {}
		explicit ListIterator(std::shared_ptr<ListNode<T>> _node) : node(_node) {}
	public:
		iterator &operator++() {
			node = node->next;
			return *this;
		}
		iterator &operator++(int) {
			iterator &tmp = *this;
			node = node->next;
			return tmp;
		}
		iterator &operator--() {
			node = node->prev;
			return *this;
		}
		iterator &operator--(int) {
			iterator &tmp = *this;
			node = node->prev;
			return tmp;
		}
		bool operator==(iterator other) { return this->node == other->node; }
		bool operator!=(iterator other) { return this->node != other->node; }
		iterator *operator->() { return this; }
		reference operator*() { return this->node->val; }
	};

	template <typename T>
	class LinkedList {
	public:
		typedef ListIterator<T> iterator;
		typedef std::shared_ptr<ListNode<T>> pointer;
	protected:
		pointer list = nullptr;
		uint64_t len = 0;
	public:
		explicit LinkedList() : len(0), list(nullptr) {
			this->list = std::make_shared<ListNode<T>>();
			list->next = list;
			list->prev = list;
		}

		explicit LinkedList(uint64_t _len) : len(_len) {
			this->list = std::make_shared<ListNode<T>>();
			std::shared_ptr<ListNode<T>> p = list;
			for (uint64_t i = 0; i < _len; ++i) {
				p->next = std::make_shared<ListNode<T>>();
				p->next->prev = p,
				p->next->next = this->list;
				p = p->next;
				list->prev = p;
			}
		}

		explicit LinkedList(uint64_t _len, T _val) : len(_len) {
			this->list = std::make_shared<ListNode<T>>();
			std::shared_ptr<ListNode<T>> p = list;
			for (uint64_t i = 0; i < _len; ++i) {
				p->next = std::make_shared<ListNode<T>>(_val, this->list, p);
				p = p->next;
				list->prev = p;
			}
		}
	public:
		inline ListNode<T> *data() { return list.get(); }

		inline uint64_t size() { return this->len; }

		inline bool empty() { return this->len == 0; }

		inline iterator begin() { return *(new iterator(this->list->next)); }

		inline iterator end() { return *(new iterator(this->list)); }

		inline void pop_back() { /* TODO */ }

		inline void push_back() { /* TODO */ }
	};


} // DataStructure

#endif //DATA_STRUCTURE_LINKEDLIST_H
