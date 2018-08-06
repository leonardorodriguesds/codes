from collections import Counter


exchanges = []
while True:
    read = input()
    _a_, _b_ = (int(x) for x in read.split())
    if _a_ is 0 and _b_ is 0:
        break
    _exchange_ = list()
    _exchange_.append(read)
    _exchange_.append(input())
    _exchange_.append(input())
    exchanges.append(_exchange_)

for exchange in exchanges:
    a, b = (int(x) for x in exchange[0].split())
    if a is 0 or b is 0:
        print(0)
        continue

    exchange[1] = list(int(x) for x in exchange[1].split())
    exchange[2] = list(int(x) for x in exchange[2].split())
    _exchange_a = set(exchange[1])
    _exchange_b = set(exchange[2])
    apply_exchange = list(_exchange_a) + list(_exchange_b)
    _exchanges_repeated = set(list((Counter(apply_exchange) - Counter(list(set(apply_exchange)))).elements()))
    c_exchange_a = len(_exchange_a)
    c_exchange_b = len(_exchange_b)
    print(c_exchange_a - len(_exchanges_repeated) if c_exchange_a < c_exchange_b else c_exchange_b - len(_exchanges_repeated))