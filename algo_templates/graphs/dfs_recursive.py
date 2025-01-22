def fn(graph):
	def dfs(node):
		ans = 0
		# Do some logic
		for neighbor in graph[node]
			if neighbor not in seen:
				seen.add(neighbor)
				ans += dfs(neighbor)

		return ans

	seen = {STARTING_NODE}
	return dfs(START_NODE)
