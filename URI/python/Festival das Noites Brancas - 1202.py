def fibonacci(n, computed):
    if n not in computed:
        computed[n] = fibonacci(n - 1, computed) + fibonacci(n - 2, computed)
    return computed[n]


num = int(input())
instances = list()
for z in range(0, num):
    instances.append(input())

fib = {0: 0, 1: 1}
for instance in instances:
    number = int('{:d}'.format(int(instance, 2)))
    num = fibonacci(number, fib)
    print('{0:0=3d}'.format(num % 1000))