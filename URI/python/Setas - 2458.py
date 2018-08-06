_num_ = int(input())
table = list()
blacklist = list()
for _z_ in range(0, _num_):
    table.append(input())

for _i_ in range(0, _num_):
    if table[_i_][0] is '<':
        blacklist.append(str(_i_) + ' ' + str(0))
    if table[0][_i_] is 'A':
        blacklist.append(str(0) + ' ' + str(_i_))
    if table[_i_][(_num_ - 1)] is '>':
        blacklist.append(str(_i_) + ' ' + str((_num_ - 1)))
    if table[(_num_ - 1)][_i_] is 'V':
        blacklist.append(str((_num_ - 1)) + ' ' + str(_i_))

for _block_ in blacklist:
    i, y = (int(x) for x in _block_.split())
    if i > 0:
        if table[i - 1][y] is 'V':
            blacklist.append(str(i - 1)+' '+str(y))
    if i < (_num_ - 1):
        if table[i + 1][y] is 'A':
            blacklist.append(str(i + 1)+' '+str(y))
    if y > 0:
        if table[i][y - 1] is '>':
            blacklist.append(str(i)+' '+str(y - 1))
    if y < (_num_ - 1):
        if table[i][y + 1] is '<':
            blacklist.append(str(i)+' '+str(y + 1))

print(pow(_num_, 2) - len(blacklist))