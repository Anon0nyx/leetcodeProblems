def reverse_linked_list(head):
	curr = head
	prev = None

	while curr:
		next_node = current.next
		curr.next = prev
		prev = curr 
		curr = next_node # Iterate over to our next node

	return prev
