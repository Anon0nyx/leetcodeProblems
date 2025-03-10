def fixData(nums1: list, nums2: list) -> list:
	dist = len(nums2) - len(nums1)
	newNums1 = [0] * dist
	for num in nums1:
		newNums1.append(num)
	return newNums1

foo = [57,58,59]
bar = [69,70,71,72,73,74]

fixedFoo = fixData(foo, bar)

print(fixedFoo)
print(bar)
