numbers = []
while True:
    try:
        read = input()
        if read is '':
            break
        numbers.append(read)
    except EOFError:
        break

for sum in numbers:
    n1, n2 = (int(x) for x in sum.split())
    print("{}".format(n1 ^ n2))