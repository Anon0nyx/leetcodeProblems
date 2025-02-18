def dfs(graph):
	stack = [START_NODE]
	seen = {START_NODE}
	ans = 0

	while stack:
		node = stack.pop()
		# Do some logic
		for neighbor in graph[node]:
			if neighbor not in seen:
				seen.add(neighbor)
				stack.append(neighbor)

	return ans
