while True:
    num = int(input())
    if num > 0:
        break
A = 1
print("1 1 1")
for x in range(1, (num * 2)):
    if (x % 2) is 0:
        A = A + 1
        print("{} {} {}".format(A, pow(A, 2), pow(A, 3)))
    else:
        print("{} {} {}".format(A, pow(A, 2) + 1, pow(A, 3) + 1))