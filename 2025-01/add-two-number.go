// https://leetcode.com/problems/add-two-numbers/

/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */

func val(l *ListNode) int {
	if l == nil {
		return 0
	}

	return l.Val
}

func addTwoNumbers(l1 *ListNode, l2 *ListNode) *ListNode {
	res := &ListNode{}
	cur := &ListNode{}

	var temp int = 0

	for l1 != nil && l2 != nil {
		cur.Val = temp
		if l1 != nil {
			cur.Val += l1.Val
			l1 = l1.Next
		}
		if l2 != nil {
			cur.Val += l2.Val
			l2 = l2.Next
		}

		temp = 0

		if cur.Val >= 10 {
			cur.Val -= 10
			temp = 1
		}

		if res.Next == nil {
			res.Val = cur.Val
			res.Next = cur
		}
		cur.Next = &ListNode{}
	}

	return res
}
