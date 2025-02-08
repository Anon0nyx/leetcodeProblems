def permute(nums):
	result = []

	def backtrack(path, level):
		print(path)
		if len(path) == len(nums):
			result.append(path)
			return
		for num in nums:
			print("On number: " + str(num) + " and level : " + str(level))
			if num not in path:
				print("appending number: " + str(num))
				path.append(num)
				backtrack(path, level + 1)
				path.pop()

	backtrack([], 0)
	return result

permute([1,2,3])
