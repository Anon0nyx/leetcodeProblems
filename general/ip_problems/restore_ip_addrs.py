def findAddrs(s: str) -> str:
	res = []
	if len(s) > 12:
		return res

	def backtrack(i, dots, addr):
		if i == len(s) and dots == 4:
			res.append(addr[:-1])
			return
		if dots > 4:
			return

		for j in range(i, min(i+3, len(s))):
			if s[i:j+1] < 256 and (i == j or s[i] != "0"):
				backtrack(i+1, dots+1, addr + s[i:j+1] + ".")

	backtrack(0,0,"")
	return res
