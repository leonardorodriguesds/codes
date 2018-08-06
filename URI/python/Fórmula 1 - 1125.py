cases = []
while True:
    read = input()
    _G_, _P_ = list(map(int, read.split()))
    if _G_ is 0 and _P_ is 0:
        break
    _case_ = list()
    _case_.append(read)
    _case_results_ = list()
    for _i_ in range(0, _G_):
        _case_results_.append(input())
    _case_.append(_case_results_)
    _S_ = int(input())
    _case_.append(_S_)
    _case_s_ = list()
    for _y_ in range(0, _S_):
        _case_s_.append(input())
    _case_.append(_case_s_)
    cases.append(_case_)

for case in cases:
    G, P = (int(x) for x in case[0].split())
    for y in range(0, G):
        case[1][y] = list(int(x) for x in case[1][y].split())
    S = int(case[2])
    for i in range(0, S):
        points = [0] * P
        _bigger_ = 0
        case[3][i] = list(int(x) for x in case[3][i].split())
        for y in range(0, G):
            for z in range(0, P):
                if case[1][y][z] > case[3][i][0]:
                    continue
                points[z] += case[3][i][case[1][y][z]]
                _bigger_ = points[z] if _bigger_ < points[z] else _bigger_
        winners = list()
        for z in range(0, P):
            if points[z] is _bigger_:
                winners.append(z + 1)
        print(" ".join(map(str, winners)))