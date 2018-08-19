class NodeT:
    def __init__(self, value):
        self.value = value
        self.left = None
        self.right = None
        self.depth = 0
    def addElement(self, element):
        if element <= self.value:
            if self.left is None:
                aux = NodeT(element)
                aux.depth = self.depth + 1
                self.left = aux
            else:
                self.left.addElement(element)
        else:
            if self.right is None:
                aux = NodeT(element)
                aux.depth = self.depth + 1
                self.right = aux
            else:
                self.right.addElement(element)
    def dfs(self):
        ans = self.depth
        if self.left is not None:
            ans = max(ans, self.left.dfs())
        if self.right is not None:
            ans = max(ans, self.right.dfs())
        return ans        
    def listDepth(self):
        count = self.dfs()
        ans = [[] for i in range(count + 1)]
        self.createList(ans)
        return ans
    def createList(self, ans):
        ans[self.depth].append(self.value)
        if self.left is not None:
            self.left.createList(ans)
        if self.right is not None:
            self.right.createList(ans)

num = int(input())
tree = None
elements = [int(i) for i in input().split(' ')]
for x in elements:
    if tree is None:
        tree = NodeT(x)
    else:
        tree.addElement(x)
lists = tree.listDepth()
for i, e in enumerate(lists):
    print("Depth: %d" % (i))
    for x in e:
        print("%d " % x, end = " ")
    print("")
    