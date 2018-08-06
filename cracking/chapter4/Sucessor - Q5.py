class NodeT:
    def __init__(self, value):
        self.left = None
        self.right = None
        self.value = value
        self.parent = None
    def addElement(self, element):
        if element <= self.value:
            if self.left is None:
                aux = NodeT(element)
                self.left = aux
                self.left.parent = self
            else:
                self.left.addElement(element)
        else:
            if self.right is None:
                aux = NodeT(element)
                self.right = aux
                self.right  .parent = self
            else:
                self.right.addElement(element)
    def getmostleft(self):
        if self.left is not None:
            return self.left.getmostleft()
        return self
    def getsuccessor(self):
        if self.right is not None:
            return self.right.getmostleft().value
        else:
            q = self
            x = self.parent
            while x is not None and x.left is not q:
                q = x
                x = x.parent
            if x is not None:
                return x.value
        return None
    def search(self, value):
        if self.value is value:
            return self
        if self.value > value and self.left is not None:
            return self.left.search(value)
        if self.value < value and self.right is not None:
            return self.right.search(value)
        return None

num = int(input())
tree = None
elements = [int(i) for i in input().split(' ')]
for x in elements:
    if tree is None:
        tree = NodeT(x)
    else:
        tree.addElement(x)
q = int(input())
for i in range(0, q):
    n = int(input())
    node = tree.search(n)
    if node is not None:
        successor = node.getsuccessor()
        if successor is not None:
            print("%d" % successor)
            continue
    print("That node don't have successor!")