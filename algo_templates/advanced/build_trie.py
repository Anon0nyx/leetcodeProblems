# Using a class is only necessary if we want to store data at each node
# otherwise we can implement a true using only hash maps

class TrieNode:
	def __init__(self):
		# Here we can store data
		self.data = None
		self.children = {}

def fn(words: list) -> TrieNode:
	root = TrieNode()

	for word in words:
		curr = root
		for c in word:
			if c not in curr.children:
				curr.children[c] = TrieNode()
			curr = curr.children[c]
		# At this point we have a fill word a curr
		# We can perform more logic here if we want to
		# add additional attributes

	return root
