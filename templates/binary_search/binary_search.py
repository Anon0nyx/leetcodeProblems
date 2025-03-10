def binary_search(arr: list, target: int) -> int:
	left = 0
	right = len(arr) - 1

	while left <= right:
		mid = (left + right) // 2
		
		if arr[mid] == target:
			return mid

		if arr[mid] > target:
			right = mid - 1
		else:
			left = mid + 1

	# Left is the insertion point
	return left

arr = [1,2,4,5,6,7,11,21,23,24,26,30, 31, 32, 33]
print(binary_search(arr, 23))
