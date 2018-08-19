import math

class Node:
    left = None
    right = None
    def __init__(self, value):
        self.value = value

def is_bst(root, min, max):
    if root.left is not None and is_bst(root.left, min, root.value) is False:
        return False
    if root.right is not None and is_bst(root.right, root.value + 1, max) is False:
        return False
    return min <= root.value <= max

root = Node(10)
root.left = Node(5)
root.right = Node(30)
root.right.left = Node(11)
root.left.left = Node(3)
root.left.right = Node(10)
if is_bst(root, -math.inf, math.inf) is False:
    print("Isn't a valid BST!")
else:
    print("Really's a valid BST!")