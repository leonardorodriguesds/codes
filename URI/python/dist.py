import math
points = []
read = []
while (len(points) < 4):
    read = input().split()
    for item in read:
        points.append(float(item))
x1, y1, x2, y2 = (x for x in points)
dist = math.sqrt(pow(x2-x1, 2)+pow(y2-y1, 2))
print("{0:.4f}".format(dist))