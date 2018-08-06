inputs = []
read = []
while (len(inputs) < 2):
    read = input().split()
    for item in read:
        inputs.append(int(item))
hours, speed = (x for x in inputs)   #hours, km/h
fuel = float((hours*speed)/12)
print("{0:.3f}".format(fuel))