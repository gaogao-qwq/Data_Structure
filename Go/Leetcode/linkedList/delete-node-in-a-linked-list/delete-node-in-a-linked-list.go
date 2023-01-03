package main

import "fmt"

type ListNode struct {
	Val  int
	Next *ListNode
}

func deleteNode(node *ListNode) {
	node.Val = node.Next.Val
	node.Next = node.Next.Next
}

func main() {
	var head *ListNode = &ListNode{Val: 4, Next: &ListNode{Val: 5, Next: &ListNode{Val: 1, Next: &ListNode{Val: 9, Next: nil}}}}
	deleteNode(head.Next)
	for ptr := head; ptr != nil; ptr = ptr.Next {
		fmt.Printf("%v->", ptr.Val)
	}
}
