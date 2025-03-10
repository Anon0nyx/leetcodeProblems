def main() -> None:
	res = []
	for _ in range(int(input("Number of pairs: "))):
		name = input("Name: ")
		score = float(input("Score: "))
		res.append([name, score])

	lowVal = float("inf")
	for pair in res:
		if (score := pair[1]) < lowVal:
			lowVal = score

	for pair in res:
		score = pair[1]
		if score < lowVal:
			lowVal = score

	secondLow = float("inf")
	for pair in res:
		if secondLow > (score := pair[1]) > lowVal:
			secondLow = score

	nameArr = []
	for pair in res:
		if (score := pair[1]) == secondLow and (name := pair[0]) != "":
			nameArr.append(name)

	for name in sorted(nameArr):
		print(name)

if __name__ == "__main__":
	main()
