def count_step_fibonacci(n, count_step = {0: 1, 1: 1}):
    if n not in count_step:
        count_step[n] = count_step_fibonacci(n - 1, count_step) + count_step_fibonacci(n - 2, count_step) + 1
    return count_step[n]


def convert_to_base(number, base):
    if number is 0:
        return 0
    sign = 1
    if number < 0:
        sign = -1
    digits = []
    number *= sign
    while number >= 1:
        digits.append(int(number % base))
        number /= base

    if sign < 0:
        digits.append('-')
    digits.reverse()
    return int(''.join(map(str, digits)))


numbers = []
bases = []
while True:
    n, b = (int(x) for x in input().split())
    if n is 0 and b is 0:
        break
    numbers.append(n)
    bases.append(b)

for i in range(0, len(numbers)):
    #count_ = convert_to_base(count_step_fibonacci(numbers[i]), bases[i])
    #print("Case {}: {} {} {}".format(i + 1, numbers[i], bases[i], count_ % bases[i]))