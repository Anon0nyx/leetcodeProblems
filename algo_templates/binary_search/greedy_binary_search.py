def greedy_binary_search_minimum(arr):
	def check(x):
		# This function is implemented when needed
		return BOOLEAN

	left = MINIMUM_POSSIBLE_ANSWER
	right = MAXIMUM_POSSIBLE_ANSWER

	while left <= right:
		mid = (left + right) // 2
		if check(mid):
			right = mid - 1
		else:
			left = mid + 1

	return left

def greedy_binary_search_maximum(arr):
	def check(x):
		# Implemented as needed
		return BOOLEAN

	left = MINIMUM_POSSIBLE_ANSWER
	right = MAXIMUM_POSSIBLE_ANSWER
	while left <= right:
		mid = (left + right) // 2
		if check(mid):
			left = mid + 1
		else:
			right = mid - 1

	return right
