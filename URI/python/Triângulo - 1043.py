import math

A, B, C = (round(float(x), 1) for x in input().split())
if abs(B - C) < A < B + C or abs(A - C) < B < A + C or abs(A - B) < C < A + B:
    P = (A + B + C) / 2
    area = math.sqrt(P * (P - A) * (P - B) * (P - C))
    print(area)
else:
    print(A + B + C)