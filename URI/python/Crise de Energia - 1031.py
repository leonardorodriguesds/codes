regions = list()
while True:
    read = int(input())
    if read is 0:
        break
    regions.append(read)

for region in regions:
    region = int(region)
    if region is 13:
        print(1)
        continue
    _regions_ = list(range(1, region + 1))
    u_regions = list(_regions_)
    i = 0
    _diff_ = 2
    _remove_ = 0
    while len(u_regions):
        if len(u_regions) is 1 and u_regions[0] is 13:
            print((_diff_ + 1))
            break
        elif len(u_regions) is 1 and u_regions[0] is not 13:
            _diff_ += 1
            i = 0
            u_regions = list(_regions_)
            continue
        else:
            u_regions.pop(i)
            i += _diff_ if (i + _diff_) < len(u_regions) else (-i + ((i + _diff_) % len(u_regions)))