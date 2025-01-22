def dfs(root):
	stack = [root]
	ans = 0

	while stack:
		node = stack.pop()

		# Perform logic
		
		if node.left:
			stack.append(node.left)
		
		if node.right:
			stack.append(node.right)

	return ans
