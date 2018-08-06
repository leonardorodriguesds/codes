from datetime import datetime
__start__ = datetime.now()


def get_ways(fork, start, end):
    pile = [(start, [start])]
    while pile:
        vertex, way = pile.pop()
        if end in set(fork[vertex]):
            return way
        for _next_ in set(fork[vertex]) - set(way):
            if _next_ == end:
                return way + [_next_]
            else:
                pile.append((_next_, way + [_next_]))


N = int(input())
cards = list((int(x) for x in input().split()))
egdes = list()
for y in range(0, N):
    egdes.append(list())
for z in range(0, N - 1):
    i1, i2 = (int(x) - 1 for x in input().split())
    egdes[i1].append(i2)
    egdes[i2].append(i1)

count = 0
_start_ = datetime.now()
print(_start_ - __start__)
for i in range(1, int(N / 2) + 1):
    index = list(int(index) for index, x in enumerate(cards) if x == i)
    count += (len(get_ways(egdes, index.pop(0), index.pop(0))) - 1)
print(datetime.now() - _start_)
print(count)