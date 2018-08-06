population = []
growth = []
num = None
controll = 0
while True:
    if num == 0:
        break
    line = input().split()
    if num is None:
        num = int(line[0])
        line.pop(0)
        if num < 1 or num > 3000:
            num = None
            continue
        else:
            num = num * 4
    for item in line:
        if num == 0:
            break
        if controll <= 1:
            number = int(item)
            if number >= 100 and number <= 1000000:
                population.append(number)
                num -= 1
                controll += 1
        elif controll <= 3:
            number = float(item)
            if number >= 0.1 and number <= 10.0:
                growth.append(number)
                num -= 1
                controll += 1

for x in population:
    print("{}".format(x))