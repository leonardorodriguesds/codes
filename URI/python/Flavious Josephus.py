nc = 0
while nc < 30:
    try:
        n, k = (int(x) for x in input().split())
        if n < 1 or n > 10000 or k < 1 or k > 1000:
            continue
        people = list(range(1, n+1))
        i = 0
        k -= 1
        while n > 1:
            i = i + k if i + k < n else (i + k) % n
            people.pop(i)
            n -= 1

        print("Case {}: {}".format(nc + 1, people.pop()))
        nc += 1
    except ValueError:
        continue
    else:
        continue