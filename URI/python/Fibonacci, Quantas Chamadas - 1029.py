def fibonacci(n, computed = {0: 0, 1: 1}):
    if n not in computed:
        computed[n] = fibonacci(n-1, computed) + fibonacci(n-2, computed)
    return computed[n]


def count_step_fibonacci(n, count_step = {0: 0, 1: 0, 2: 2}):
    if n not in count_step:
        count_step[n] = count_step_fibonacci(n-1, count_step) + count_step_fibonacci(n-2, count_step) + 2
    return count_step[n]


num = int(input())
inputs = []
for x in range(0, num):
    try:
        read = input()
        if read is '':
            break
        inputs.append(int(read))
    except EOFError:
        break


for number in inputs:
    print("fib({}) = {} calls = {}".format(number, count_step_fibonacci(number), fibonacci(number)))