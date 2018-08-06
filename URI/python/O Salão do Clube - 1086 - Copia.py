from datetime import datetime


def fill_table(_width, _height, _board_width, _board_count, _boards):
    funcion_start = datetime.now()
    _width *= 100
    _count_boards = int(_width / _board_width)
    if _count_boards > _board_count or _count_boards is 0 or (_width % _board_width) is not 0:
        return -1
    _result = 0
    count_height = _boards.count(_height)
    _result += count_height if count_height < _count_boards else _count_boards
    _count_boards -= _result
    if _count_boards is 0:
        return _result
    _boards = [e for e in _boards if e < _height]
    i = 0
    print("Combinando pares start: ", datetime.now() - funcion_start)
    while i < len(_boards) - 1:
        _e = _boards[i]
        _sum = _height - _e
        if _sum in _boards[i + 1:]:
            _boards.remove(_sum)
            _result += 2
            _count_boards -= 1
        if _count_boards is 0:
            break
        i += 1
    print("Combinando pares end: ", datetime.now() - funcion_start, " - i: ", i)
    if _count_boards is 0:
        return _result
    else:
        return -1


inputs = []
while True:
    read = input()
    _width_, _height_ = (int(x) for x in read.split())
    if _width_ is 0 and _height_ is 0:
        break
    _hall_ = list()
    _hall_.append(read)     #Width, height
    _hall_.append(input())  #boards width
    _hall_.append(input())  #board count
    _hall_.append(input())  #boards heights
    inputs.append(_hall_)

for hall in inputs:
    start = datetime.now()
    print("Start: ", start)
    width, height = (int(x) for x in hall[0].split())
    board_width = int(hall[1])
    board_count = int(hall[2])
    boards = list(int(x) for x in hall[3].split())
    print("Chamando a função: ", datetime.now() - start)
    result_width = fill_table(width, height, board_width, board_count, boards)
    print("Resultado: ", datetime.now() - start)
    result = result_width
    if width != height:
        result_height = fill_table(height, width, board_width, board_count, boards)
        result = result_width if (result_width is not -1 and result_width < result_height) or result_height is -1 else result_height
    if result is -1:
        print("impossivel")
    else:
        print(result)