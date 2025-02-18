from collections import dequq

def fn(graph):
	queue = deque([START_NODE])
	seen = {START_NODE}
	ans = 0

	while queue:
		node = queue.popleft()
		# Do some logic
		for neighbor in graph[node]:
			if neighbor not in seen:
				seen.add(neighbor)
				queue.append(neighbor)

	return ans
