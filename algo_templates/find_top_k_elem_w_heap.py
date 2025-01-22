import heapq

def find_top_k_elem(arr: list, k: int) -> list:
	heap = []

	for num in arr:
		# Do some logic here to push onto heap according to problem criteria
		heapq.heappush(heap, (CRITERIA, num))
		if len(heap) > k:
			heapq.heappop(heap)

	return [num for num in heap]
