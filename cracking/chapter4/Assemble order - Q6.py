from heapq import heappush, heappop

class Graph:
    def __init__(self, num, directed = False):
        self.n = num
        self.directed = directed
        self.adj = [[] for i in range(num)]
        self.outbound = [0 for i in range(num)]
        self.incoming = [0 for i in range(num)]
    def addEdge(self, a, b):
        if a >= self.n or b >= self.n:
            return None
        self.adj[a].append(b)
        self.outbound[a] += 1
        self.incoming[b] += 1
        if self.directed:
            self.outbound[b] += 1
            self.incoming[a] += 1
            self.adj[b].append(a)
        return True
    def topologyorder(self):
        ince = self.incoming[:]
        count = self.n
        ans = []
        aux = []
        controll = [0 for i in range(self.n)]
        for i in range(self.n):
            heappush(aux, (ince[i], i))
        while aux and count > 0:
            incominge, u = heappop(aux)
            if incominge is 0 and controll[u] is 0:
                controll[u] = 1
                count -= 1
                ans.append(u + ord('A'))
                for v in self.adj[u]:
                    ince[v] -= 1
                    heappush(aux, (ince[v], v))
        if count is 0:
            return ans
        return None

n, m = [int(i) for i in input().split(' ')]
graph = Graph(n, False)
for i in range(0, m):
    a, b = [ord(i) for i in input().split(' ')]
    a -= ord('A')
    b -= ord('A')
    if graph.addEdge(a, b) is None:
        print("Couldn't create this edge!")
ans = graph.topologyorder()
if ans is not None:
    for u in ans:
        print("%c" % u, end = " ")
    print("")
else:
    print("Topological sorting is not possible!")