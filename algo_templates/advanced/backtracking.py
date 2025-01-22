def backtrack(curr, OTHER_ARGS...):
	if (BASE_CASE):
		# Modify our answer
		return

	ans = 0
	for (ITERATE_OVER_INPUT):
		# Modify the current state
		ans += backtrack(curr, OTHER_ARGS...)
		# Undo the modification of the current state

	return ans
