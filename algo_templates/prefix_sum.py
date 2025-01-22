def prefix_sum(arr: list) -> list:
	prefix = arr[0]
	for i in range(1, len(arr)):
		prefix.append(prefix[-1] + arr[i])

	return prefix
