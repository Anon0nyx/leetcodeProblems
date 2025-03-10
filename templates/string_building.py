# Arr is a list of characters
def create_string(arr: list) -> str:
	ans = []
	for c in arr:
		ans.append(c)

	return "".join(ans)
