import math

ducks = list()
while True:
    try:
        read = input()
        if read == '':
            break
        _duck_ = list()
        _duck_.append(read)
        _duck_.append(input())
        _n_ = int(input())
        _duck_.append(_n_)
        for z in range(0, _n_):
            _duck_.append(input())
        ducks.append(_duck_)
    except EOFError:
        break

for duck in ducks:
    h, n = float(duck.pop(0)), int(duck.pop(1))
    p1, p2 = (int(x) for x in duck.pop(0).split())
    g, pi = 9.80665, 3.14159
    for angry in duck:
        angle, speed = (float(x) for x in angry.split())
        angle = (angle * pi) / 180
        Vy = speed * math.sin(angle)
        delta = math.sqrt(math.pow(Vy, 2) + 2*g*h)
        if delta < 0:
            continue
        t = (-Vy + delta) / (-g)
        if delta > 0:
            t2 = (-Vy - delta) / (-g)
            t = t if t >= t2 else t2
        Vx = speed * math.cos(angle)
        distanceh = Vx * t
        print("{0:.5f} -> {1}".format(distanceh, 'DUCK' if float(p1) <= distanceh <= float(p2) else 'NUCK'))