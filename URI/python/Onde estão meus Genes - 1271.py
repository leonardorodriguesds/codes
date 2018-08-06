genomes = list()
while True:
    read = input()
    if read == '0':
        break
    _genome_ = list()
    _genome_.append(read)
    _r_ = int(input())
    _genome_.append(_r_)
    for _z_ in range(0, _r_):
        _genome_.append(input())
    _q_ = int(input())
    _genome_.append(_q_)
    for _y_ in range(0, _q_):
        _genome_.append(input())
    genomes.append(_genome_)

z = 0
for queries in genomes:
    z += 1
    N, R = int(queries.pop(0)), int(queries.pop(0))
    Q = int(queries.pop(R))
    inversions = queries[:R]
    queries = queries[R:]
    genome = list(range(1, N + 1))
    for i in range(0, R):
        x, y = (int(x) for x in inversions[i].split())
        inversion = genome[x - 1:y]
        inversion.reverse()
        genome = genome[:x - 1] + inversion + genome[y:]
    print("Genome", z)
    for y in range(0, Q):
        num = int(queries[y])
        print(genome.index(num) + 1)