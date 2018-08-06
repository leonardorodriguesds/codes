from datetime import datetime
start_all = datetime.now()

def fill_table(_width, _height, _board_width, _board_count, _boards):
    funcion_start = datetime.now()
    _width *= 100
    _count_boards = int(_width / _board_width)
    if _count_boards > _board_count or _count_boards is 0 or (_width % _board_width) is not 0:
        return -1
    _result = 0
    _acess_list = set(_boards)
    if _height in _acess_list:
        count_height = _boards.count(_height)
        _result += count_height if count_height < _count_boards else _count_boards
        _count_boards -= _result
        if _count_boards is 0:
            return _result
        _acess_list.remove(_height)
    i = 0
    print("Combinando pares start: ", datetime.now(), ", tempo até aqui: ", datetime.now() - funcion_start)
    _black_list = set()
    start_loop = datetime.now()
    while i < len(_boards) - 1:
        _e = _boards[i]
        if _e not in _acess_list:
            i += 1
            continue
        _sum = _height - _e
        if _sum is not _e:
            _acess_list.remove(_e)
        if _sum is _e or _sum in _acess_list:
            _count_e = _boards.count(_e)
            if _sum is _e and _count_e is 1:
                _acess_list.remove(_e)
                i += 1
                continue
            if _sum is not _e:
                _count_sum = _boards.count(_sum)
            else:
                _count_e = int(_count_e / 2)
                _count_sum = _count_e
            _count_total = _count_e if _count_e < _count_sum else _count_sum
            _result += _count_total * 2 if _count_total < _count_boards else _count_boards * 2
            _count_boards -= _count_total if _count_total < _count_boards else _count_boards
            _acess_list.remove(_sum)
        if _count_boards is 0:
            break
        i += 1
    print("Combinando pares end: ", datetime.now() - funcion_start, ", tempo de execução: ", datetime.now() - start_loop)
    print("_count_boards: ", _count_boards, ", _result: ", _result, ", i: ", i)
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
    print("Start: ", start - start_all)
    width, height = (int(x) for x in hall[0].split())
    board_width = int(hall[1])
    board_count = int(hall[2])
    boards = list(int(x) for x in hall[3].split())
    print("Chamando a função: ", datetime.now() - (start - start_all))
    start_function = datetime.now()
    result_width = fill_table(width, height, board_width, board_count, boards)
    print("Tempo de execução da função: ", datetime.now() - start_function)
    result = result_width
    if width != height:
        result_height = fill_table(height, width, board_width, board_count, boards)
        result = result_width if (result_width is not -1 and result_width < result_height) or result_height is -1 else result_height
    if result is -1:
        print("impossivel")
    else:
        print(result)


print(datetime.now() - start_all)