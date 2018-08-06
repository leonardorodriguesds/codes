cases = []
while True:
    read = input()
    A, B, C, D = (int(x) for x in read.split())
    if A is 0 and B is 0 and C is 0 and D is 0:
        break
    numbers = []
    numbers.append(A)
    numbers.append(B)
    numbers.append(C)
    numbers.append(D)
    cases.append(numbers)


for _numbers_ in cases:
    count = 0
    if _numbers_[0] is not _numbers_[2] or _numbers_[1] is not _numbers_[3]:
        count = 1
        if _numbers_[0] is not _numbers_[2] and _numbers_[1] is not _numbers_[3] and abs(_numbers_[1] - _numbers_[3]) is not abs(_numbers_[0] - _numbers_[2]):
            count = 2
    print(count)