_num_ = int(input())
inputs = list()
for z in range(0, _num_):
    inputs.append(input())

i = 0
for number in inputs:
    i += 1
    num, base = number.split()
    if base == 'hex':
        num = int(num, 16)
    elif base == 'bin':
        num = int(num, 2)
    else:
        num = int(num)
    convert = list()
    if base == 'bin':
        convert.append(str('{:d}'.format(num)) + ' dec')
        convert.append(str('{:x}'.format(num)) + ' hex')
    elif base == 'dec':
        convert.append(str('{:x}'.format(num)) + ' hex')
        convert.append(str('{:b}'.format(num)) + ' bin')
    elif base == 'hex':
        convert.append(str('{:d}'.format(num)) + ' dec')
        convert.append(str('{:b}'.format(num)) + ' bin')
    print("Case {}:".format(i))
    print(convert[0])
    print(convert[1] + '\n')