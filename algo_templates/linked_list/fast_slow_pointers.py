def fn(head):
	slow = head
	fast = head
	ans = 0

	while fast and fast.next:
		# Perform logic
		slow = slow.next
		fast = fast.next.next

	return ans
