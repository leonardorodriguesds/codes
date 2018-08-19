'''
4.8 - First commom ancestor of BT:
Design an algorithm and write code to find the first commom ancestor of two
nodes in binary tree. Avoid storing additional nodes in a data structure. 
NOTE: this is not necessarily a binary search tree.
'''

class Node:
    def __init__(self, value):
        self.left = None
        self.right = None
        self.value = value
    def getFCA(self, lhs, rhs):
        if (self is lhs or self is rhs): return self
        leftc, rightc = None, None
        if (self.left is not None): leftc = self.left.getFCA(lhs, rhs)
        if (self.right is not None): rightc = self.right.getFCA(lhs, rhs)
        if (leftc is not None and rightc is not None): return self
        if (leftc is not None): return leftc
        if (rightc is not None): return rightc
        return None 

tree = Node(5)
tree.left = Node(20)
tree.left.left = Node(15)
tree.left.right = Node(40)
tree.right = Node(2)
tree.right.left = Node(10)
tree.right.right = Node(45)
tree.right.right.right = Node(55)
ans = tree.getFCA(tree.left.left, tree.left.right)
if (ans is not None): print("%d" % ans.value)
else: print("None")