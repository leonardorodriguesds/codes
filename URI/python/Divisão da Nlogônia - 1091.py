inputs = []
while True:
    n = int(input())
    if n is 0:
        break
    cases = list()
    cases.append(n)
    cases.append(input())
    for _i_ in range(0, n):
        cases.append(input())
    inputs.append(cases)

for _case_ in inputs:
    _num_ = int(_case_[0])
    rotX, rotY = (int(x) for x in _case_[1].split())
    for i in range(0, _num_):
        x, y = (int(x) for x in _case_[2 + i].split())
        if x > rotX and y > rotY:
            print("NE")
        elif x < rotX and y < rotY:
            print("SO")
        elif x > rotX and y < rotY:
            print("SE")
        elif y > rotY and x < rotX:
            print("NO")
        else:
            print("divisa")