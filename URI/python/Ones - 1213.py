numbers = list()
while True:
    try:
        read = input()
        if read == '':
            break
        numbers.append(read)
    except EOFError:
        break

for number in numbers:
    n = len(number)
    number = int(number)
    num = int(''.join(str(1) for x in range(0, n + 1)))
    i = 1
    while num % number != 0:
        i += 1
        num = int(''.join(str(1) for _x_ in range(0, n + i)))
    print(len(str(num)))