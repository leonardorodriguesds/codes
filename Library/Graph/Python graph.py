class Graph:
    def __init__(self, num, directed = False):
        self.n = num
        self.directed = directed
        self.adj = [[] for i in range(num)]
    def addEdge(self, a, b):
        if a >= self.n or b >= self.n:
            return
        self.adj[a].append(b)
        if self.directed:
            self.adj[b].append(a)
    def printAll(self):
        for i in range(self.n):
            for x in self.adj[i]:
                print("%d <=> %d" % (i, x))

graph = Graph(5)
graph.addEdge(1, 0)
graph.addEdge(0, 1)
graph.addEdge(3, 4)
graph.printAll()