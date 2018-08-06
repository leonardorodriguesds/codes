import math
inputs = []
read = []
while len(inputs) < 3:
    read = input().split()
    for x in read:
        inputs.append(float(x))

A, B, C = (x for x in inputs)
delta = pow(B, 2) - 4 * A * C

if A <= 0 or delta < 0:
    print("Impossivel calcular")
    exit(0)

x1 = (-B + math.sqrt(delta)) / (2 * A)
x2 = (-B - math.sqrt(delta)) / (2 * A)
print("R1 = {0:.5f}".format(x1))
print("R2 = {0:.5f}".format(x2))