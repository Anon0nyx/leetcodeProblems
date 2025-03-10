from typing import Any

class Solution:
	def __init__(self, name: str, pages: int) -> None:
		self.title = name
		self.pages = pages
	
	def __format__(self, format_spec: Any) -> str:
		match format_spec:
			case "time":
				return f"{self.pages / 60:.2f}h"
			case "name":
				return self.title.upper()
			case _:
				raise ValueError(f"Unknown specifier for Solution()")

	def solution(self) -> None:
		pass

def main() -> None:
	foo: Solution = Solution("Notes from the Underground", 250)
	bar: Solution = Solution("The Brothers Karamazov", 700)

	print(f"Foo read time: {foo:time}")
	print(f"Foo name: {foo:name}")
	print(f"Foo read time: {bar:time}")
	print(f"Foo name: {bar:name}")
	
if __name__ == "__main__":
	main()
