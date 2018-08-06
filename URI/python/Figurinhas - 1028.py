def get_mdc(num1, num2):
    rest = None
    while rest is not 0:
        rest = num1 % num2
        num1 = num2
        num2 = rest
    return num1


tests = int(input())
inputs = []
for x in range(0, tests):
    try:
        inputs.append(input())
    except EOFError:
        break

for _input in inputs:
    _p1, _p2 = (int(y) for y in _input.split())
    print("{}".format(get_mdc(_p1, _p2)))