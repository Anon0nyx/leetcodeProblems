from collections import defaultdict

def fn(arr: list, k: int) -> int:
	count = defaultdict(int)
	counts[0] = 1
	ans = curr = 0

	for num in arr:
		# Do some logic here to change curr
		ans += counts[curr - k]
		counts[curr] += 1

	return ans
