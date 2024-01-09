func addToList(number int, current *ListNode) *ListNode {
	digit := new(ListNode)
	digit.Val = number

	if current != nil {
		current.Next = digit
	}

	return digit
}

func addTwoNumbers(l1 *ListNode, l2 *ListNode) *ListNode {
	var sum, carry int
	var first_node, current_node *ListNode

	for sum != -1 {
		sum = 0

		if l1 != nil {
			sum += l1.Val
			l1 = l1.Next
		}

		if l2 != nil {
			sum += l2.Val
			l2 = l2.Next
		}

		current_node = addToList((sum+carry)%10, current_node)
		carry = int((sum + carry) / 10)

		if first_node == nil {
			first_node = current_node
		}

		if l1 == nil && l2 == nil {
			if carry != 0 {
				current_node = addToList(carry, current_node)
			}

			break
		}
	}

	return first_node
}