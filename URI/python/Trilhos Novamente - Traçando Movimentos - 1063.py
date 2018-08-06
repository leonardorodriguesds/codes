trains = list()
while True:
    try:
        read = input()
        if read == '0':
            break
        _train_ = list()
        _train_.append(read)
        _train_.append(input())
        _train_.append(input())
        trains.append(_train_)
    except EOFError:
        break

for train in trains:
    N = int(train.pop(0))
    unorganized = list(str(x) for x in train.pop(0).split())
    pile = list()
    train = list(str(x) for x in train.pop().split())
    result = ''
    for z in train:
        if len(pile) and pile[-1] == z:
            pile.pop()
            result += 'R'
        elif len(unorganized):
            _in_ = False
            if z in unorganized:
                i = unorganized.index(z)
                _in_ = True
            else:
                i = len(unorganized) - 1
            for y in range(0, i + 1):
                pile.append(unorganized[0])
                unorganized.pop(0)
                result += 'I'
            if _in_:
                pile.pop()
                result += 'R'
            else:
                result += ' Impossible' if len(result) else 'Impossible'
                break
        else:
            result += ' Impossible' if len(result) else 'Impossible'
            break
    print(result)