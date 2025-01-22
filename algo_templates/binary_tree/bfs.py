from collections import deque

def bfs(root):
	queue = deque([root])

	ans = 0

	while queue:
		current_length = len(queue)

		# Do logic for current level

		for _ in range(current_length):
			node = queue.popleft()
			
			# Do logic

			if node.left:
				queue.append(node.left)

			if node.right:
				queue.append(node.right)

	return ans
