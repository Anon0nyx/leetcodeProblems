def dfs(root):
	if not root:
		return

	ans = 0

	# Perform logic
	dfs(root.left)
	dfs(root.right)
	
	return ans
