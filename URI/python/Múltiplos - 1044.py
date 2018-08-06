A, B = (int(x) for x in input().split())
if (A % B) is 0 or (B % A) is 0:
    print("Sao Multiplos")
else:
    print("Nao sao Multiplos")