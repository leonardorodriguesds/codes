def get_ways(fork, start, end):
    pile = [(start, [start])]
    while pile:
        vertex, way = pile.pop()
        for next in set(fork[vertex]) - set(way):
            if next == end:
                yield way + [next]
            else:
                pile.append((next, way + [next]))