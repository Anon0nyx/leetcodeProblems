def monotonic_stack(arr: list) -> int:
	stack = []
	ans = 0

	# For a monotonic decreasing stack, change the > to a <
	for num in arr:
		while stack and stack[-1] > num:
			# Do logic
			stack.pop()
		stack.append(num)

	return ans
