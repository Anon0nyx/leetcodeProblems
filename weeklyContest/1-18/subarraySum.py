def subarraySum(nums: list) -> int:
  total_sum = 0
  n = len(nums)
  for i in range(n):
    start = max(0, i - nums[i])
    for j in range(start, i + 1):
      total_sum += nums[j]
  return total_sum

print(subarraySum([2,3,1]))
print(subarraySum([3,1,1,2]))
