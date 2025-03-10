def multiples(n: int) -> list[int]:
	nums = []
	for i in range(1, n):
		if i % 3 == 0 or i % 5 == 0:
			nums.append(i)
	return nums

print(sum(multiples(1000)))
