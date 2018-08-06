inputs = []
while True:
    read = input()
    N, D = (int(x) for x in read.split())
    if N is 0 and D is 0:
        break
    _read_ = [read, input()]
    inputs.append(_read_)

for _item_ in inputs:
    N, D = (int(x) for x in _item_[0].split())
    N -= 1
    i = 0
    _number_ = _item_[1]
    while D > 0 and i < N:
        if _number_[i] is 9:
            i =+ 1
            continue

        if _number_[i] is 0 or (_number_[i] < _number_[i + 1]):
            _number_ = _number_[:i] + _number_[i + 1:]
            i -= 2 if i > 0 else 1
            D -= 1
            N -= 1
        i += 1
    if D:
        _number_ = _number_[:N - (D - 1)]
    print(_number_)