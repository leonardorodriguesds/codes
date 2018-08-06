def get_direction(_current_, _next_):
    _rootCase_ = {
        'D': 'L',
        'E': 'O'
    }
    if _current_ == 'S':
        _rootCase_ = {
            'D': 'O',
            'E': 'L'
        }
    elif _current_ == 'L':
        _rootCase_ = {
            'D': 'S',
            'E': 'N'
        }
    elif _current_ == 'O':
        _rootCase_ = {
            'D': 'N',
            'E': 'S'
        }
    return _rootCase_.get(_next_, _current_)


racings = []
while True:
    read = input()
    if read == '0 0 0':
        break
    _N_, _M_, _S_ = map(int, read.split())
    _racing_ = list()
    for _z_ in range(0, _N_):
        _line_ = input()
        _racing_.append(_line_)
        if 'N' in _line_ or 'S' in _line_ or 'L' in _line_ or 'O' in _line_:
            _find_ = _line_.find('N') if _line_.find('N') != -1 else (_line_.find('S') if _line_.find('S') != -1 else (_line_.find('L') if _line_.find('L') != -1 else _line_.find('O')))
            read = read + ' ' + str(_z_) + ' ' + str(_find_)
    _racing_.append(input())
    _racing_.append(read)
    racings.append(_racing_)

for racing in racings:
    N, M, S, startX, startY = map(int, racing.pop().split())
    instructions = racing.pop()
    x, y = startX, startY
    runCase = {
        'N': [-1, 0],
        'S': [1, 0],
        'L': [0, 1],
        'O': [0, -1]
    }  #x, y
    direction = racing[startX][startY]
    count = 0
    for i in range(0, S):
        if instructions[i] != 'F':
            direction = get_direction(direction, instructions[i])
            continue
        nX, nY = runCase.get(direction, [0, 0])
        nX, nY = x + nX, y + nY
        if 0 <= nX <= (N - 1) and 0 <= nY <= (M - 1):
            if racing[nX][nY] == '#':
                continue
            else:
                if racing[nX][nY] == '*':
                    count += 1

                racing[nX] = racing[nX][:nY] + 'x' + racing[nX][nY + 1:]
                x, y = nX, nY
    print(count)