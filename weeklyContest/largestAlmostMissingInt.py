from typing import Any

class Solution:
	def solution(self, nums: list[int], k:int) -> int:
		tracker = {}
		for val in nums:
			tracker[val] = 0

		for i in range((len(nums) - k) + 1):
			subarr = nums[i:i+k]
			for val in subarr:
				tracker[val] += 1
	
		maxVal = 0	
		for key, val in tracker.items():
			print(f"{key > maxVal and val == 1} {key} {maxVal} {val}")
			if key > maxVal and val == 1:
				print(f"MAde it with key {key}")
				maxVal = key
				print(f"New maxVal {maxVal}")	
	
		return maxVal if maxVal > 0 else -1

def main() -> None:
	foo: Solution = Solution()
	bar: Solution = Solution()
	
	num = foo.solution([3,9,7,2,1,7], 4)
	num2 = foo.solution([0,0], 1)

	print(num)
	print(num2)

	
if __name__ == "__main__":
	main()
