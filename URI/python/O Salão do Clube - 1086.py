def fill_table(_width, _height, _board_width, _board_count, _boards):
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
    inputs.append(read)     #Width, height
    inputs.append(input())  #boards width
    inputs.append(input())  #board count
    inputs.append(input())  #boards heights


for _i_ in range(0, int(len(inputs) / 4)):
    _i =  _i_ * 4
    width, height = (int(x) for x in inputs[_i + 0].split())
    board_width = int(inputs[_i + 1])
    board_count = int(inputs[_i + 2])
    boards = list(int(x) for x in inputs[_i + 3].split())
    result_width = fill_table(width, height, board_width, board_count, boards)
    result = result_width
    if width != height:
        result_height = fill_table(height, width, board_width, board_count, boards)
        result = result_width if (result_width is not -1 and result_width < result_height) or result_height is -1 else result_height
    if result is -1:
        print("impossivel")
    else:
        print(result)