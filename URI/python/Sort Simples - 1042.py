def set_growing(unorganized):
    _list_ = list(unorganized)
    i = 1
    while i < len(_list_):
        if _list_[i] < _list_[i - 1]:
            _list_[i - 1], _list_[i] = _list_[i], _list_[i - 1]
            i -= 2 if (i > 1) else 1
        i += 1
    return _list_


inputs = []
for x in input().split():
    inputs.append(int(x))
for gr in set_growing(inputs):
    print("{}".format(gr))
print("")
for number in inputs:
    print("{}".format(number))
