'''
def countPossibilities(n: int):
	res = [0] * (n + 1)
	res[0] = 1
	res[1] = 1

	for i in range(2, n + 1):
		res[i] = res[i - 1] + res[i - 2]

	return res[-1]
'''
def countPossibilities(n: int):
	curr = 2
	old = 1

	for i in range(3, n + 1):
		temp = curr
		curr = temp + old
		old = temp
	return curr
		
		
print(countPossibilities(5))
