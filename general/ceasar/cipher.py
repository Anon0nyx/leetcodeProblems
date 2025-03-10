def rotN(s: str, rot: int):
	s = s.lower()
	wordArr = s.split()
	newArr = []
	for word in wordArr:
		newWord = ""
		for letter in word:
			asciiVal = ord(letter)
			if asciiVal + rot > ord("z"):
				overstep = (asciiVal + rot) - ord("z")
				newChar = chr(ord("a") + overstep - 1)
				newWord += newChar
			else:
				newWord += chr(asciiVal + rot)	
		newArr.append(newWord)
	
	newStr = ""
	for word in newArr:
		newStr += word + " "

	newStr = newStr.strip()

	return newStr

for i in range(0, 26):
	print(rotN("Dro aesmu lbyg rkvc pyhzc cydr dro vkji nyq", i))
	#print("Rotation " + str(i) + " : " + rotN("what are you", i))
	#print("Rotation " + str(i) + " : " + rotN("uijt jt nz uftujoh nfttbhf", i))
