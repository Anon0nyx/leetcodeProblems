# Definition of a binary tree node
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

# Pre-order traversal
def preorder_traversal(root):
    if root:
        print(root.val, end=" ")  # Visit root
        preorder_traversal(root.left)  # Recursively traverse left subtree
        preorder_traversal(root.right)  # Recursively traverse right subtree

# In-order traversal
def inorder_traversal(root):
    if root:
        inorder_traversal(root.left)  # Recursively traverse left subtree
        print(root.val, end=" ")  # Visit root
        inorder_traversal(root.right)  # Recursively traverse right subtree

# Post-order traversal
def postorder_traversal(root):
    if root:
        postorder_traversal(root.left)  # Recursively traverse left subtree
        postorder_traversal(root.right)  # Recursively traverse right subtree
        print(root.val, end=" ")  # Visit root

# Example tree
root = TreeNode(1)
root.left = TreeNode(2)
root.right = TreeNode(3)
root.left.left = TreeNode(4)
root.left.right = TreeNode(5)
root.right.right = TreeNode(6)

# Pre-order traversal
#print("Pre-order traversal:")
#preorder_traversal(root)
#print()

# In-order traversal
print("In-order traversal:")
inorder_traversal(root)
print()

# Post-order traversal
#print("Post-order traversal:")
#postorder_traversal(root)
#print()
