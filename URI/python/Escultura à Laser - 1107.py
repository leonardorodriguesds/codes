heights = []
while True:
    read = input()
    _h_, _w_ = list(map(int, read.split()))
    if _h_ is 0 and _w_ is 0:
        break
    _height_ = list()
    _height_.append(read)
    _height_.append(input())
    heights.append(_height_)

for height in heights:
    h, w = list(map(int, height[0].split()))
    height[1] = list(map(int, height[1].split()))
    result = 0
    for i in range(0, w):
        if i is 0:
            result += h - height[1][i]
        elif height[1][i] < height[1][i - 1]:
            result += height[1][i - 1] - height[1][i]
    print(result)