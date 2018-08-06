inputs = []
read = []
while (len(inputs) < 4):
    read = input().split()
    for item in read:
        inputs.append(int(item))

A, B, C, D = (x for x in inputs)
if B > C and D > A and (C + D) > (A + B) and C > 0 and D > 0 and (A % 2) is 0:
    print("Valores aceitos")
else:
    print("Valores nao aceitos")