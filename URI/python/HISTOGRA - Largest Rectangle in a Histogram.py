from datetime import datetime
start = datetime.now()

histograms = list()
while True:
    read = input()
    if read == '0':
        break
    histograms.append(read)

for histogram in histograms:
    histogram = list(map(int, histogram))
    N = histogram.pop(0)
