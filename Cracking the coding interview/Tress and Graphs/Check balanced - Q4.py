class NodeT:
    def __init__(self, value):
        self.value = value
        self.left = None
        self.right = None
        self.height = 1
    def addElement(self, element):
        if element <= self.value:
            if self.left is None:
                aux = NodeT(element)
                self.left = aux
            else:
                self.left.addElement(element)
        else:
            if self.right is None:
                aux = NodeT(element)
                self.right = aux
            else:
                self.right.addElement(element)
        hleft = 0
        if self.left is not None:
            hleft = self.left.height
        hright = 0
        if self.right is not None:
            hright = self.right.height
        self.height = max(hleft, hright) + 1
    def balanced(self):
        hLeft = 0
        hRight = 0
        if self.left is not None:
            hleft = self.left.height
        if self.right is not None:
            hRight = self.right.height
        print("%d %d" % (hLeft, hRight))
        return hLeft - hRight

num = int(input())
tree = None
elements = [int(i) for i in input().split(' ')]
for x in elements:
    if tree is None:
        tree = NodeT(x)
    else:
        tree.addElement(x)
print("%d" % tree.balanced())
