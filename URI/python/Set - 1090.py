def get_sets(_list_):
    _sets_ = 0
    _count_ = _list_[0]
    _count_ = _list_[1] if _list_[1] < _count_ else _count_
    _count_ = _list_[2] if _list_[2] < _count_ else _count_
    if _count_:
        _list_[0] -= _count_
        _list_[1] -= _count_
        _list_[2] -= _count_
        _sets_ += _count_
    for _y_ in range(0, 3):
        _sets_ += int(_list_[_y_] / 3)
        _list_[_y_] = int(_list_[_y_] % 3)
    return _sets_


cards = list()
while True:
    _num_ = int(input())
    if _num_ is 0:
        break
    _cards_ = list()
    _cards_.append(_num_)
    for _i_ in range(0, _num_):
        _cards_.append(input())
    cards.append(_cards_)


for card in cards:
    num = int(card.pop(0))
    circle = [0] * 3
    square = [0] * 3
    triangle = [0] * 3
    _list_ = list()
    sets = 0
    number = 0
    for i in range(0, num):
        if 'circulo' in card[i] or 'circulos' in card[i]:
            _list_ = circle
        elif 'quadrado' in card[i] or 'quadrados' in card[i]:
            _list_ = square
        elif 'triangulo' in card[i] or 'triangulos' in card[i]:
            _list_ = triangle
        if 'um' in card[i]:
            number = 0
        elif 'dois' in card[i]:
            number = 1
        elif 'tres' in card[i]:
            number = 2

        _list_[number] += 1

    for y in range(0, 3):
        _count_1 = circle[y]
        _count_1 = square[((y + 1) % 3)] if square[((y + 1) % 3)] < _count_1 else _count_1
        _count_1 = triangle[((y + 2) % 3)] if triangle[((y + 2) % 3)] < _count_1 else _count_1
        _count_2 = circle[y]
        _count_2 = square[((y + 2) % 3)] if square[((y + 2) % 3)] < _count_2 else _count_2
        _count_2 = triangle[((y + 1) % 3)] if triangle[((y + 1) % 3)] < _count_2 else _count_2
        _use_ = _count_1
        if _count_2 > _count_1:
            _use_ = _count_2
        if _use_:
            circle[y] -= _use_
            square[((y + (1 if _use_ is _count_1 else 2)) % 3)] -= _use_
            triangle[((y + (2 if _use_ is _count_1 else 1)) % 3)] -= _use_
            sets += _use_

        count = circle[y]
        count = square[((y + (2 if _use_ is _count_1 else 1)) % 3)] if square[((y + (2 if _use_ is _count_1 else 1)) % 3)] < count else count
        count = triangle[((y + (1 if _use_ is _count_1 else 2)) % 3)] if triangle[((y + (1 if _use_ is _count_1 else 2)) % 3)] < count else count
        if count:
            circle[y] -= count
            square[((y + (2 if _use_ is _count_1 else 1)) % 3)] -= count
            triangle[((y + (1 if _use_ is _count_1 else 2)) % 3)] -= count
            sets += count

    sets += get_sets(circle)
    sets += get_sets(square)
    sets += get_sets(triangle)
    print(sets)