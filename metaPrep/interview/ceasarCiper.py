class Solution:
	def __init__(self, rotation: int, phrase: str) -> None:
		self.rotation = rotation
		self.phrase = phrase
		print("Running Solution.")

	def encode(self, rotation: int = None, phrase: str = None) -> str:
		rot = rotation if rotation is not None else self.rotation
		s = phrase if phrase is not None else self.phrase

		encoded = ""

		if len(s) > 26:
			rot = rot % 26

		for letter in s.upper():
			asciiVal = ord(letter)
			if asciiVal == ord(" "):
				encoded += " "
			elif asciiVal + rot > ord('Z'):
				overstep = (asciiVal + rot) - ord('Z')
				newLetter = ord("A") + overstep - 1
				encoded += chr(newLetter)
			
			else:
				encoded += chr(asciiVal + rot)

		return encoded

	def decode(self) -> str:
		return self.encode(26 - self.rotation, self.encode(self.rotation, self.phrase))

def main() -> None:
	solution: Solution = Solution(5, "Hello There")
	encoded = solution.encode()
	print(encoded)

	decoded = solution.decode()
	print(decoded)

if __name__ == "__main__":
	main()
