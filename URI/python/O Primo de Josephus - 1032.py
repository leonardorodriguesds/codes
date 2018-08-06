def get_next_prime(num):
    num += 1 if num is 2 or num is 1 else 2
    for x in range(2, int(num ** 0.5) + 1):
        if num % x == 0:
            return get_next_prime(num)
    return num


inputs = []
read = []
number = -1
while number != 0:
    read = input().split()
    for number in read:
        number = int(number)
        if number is 0:
            break
        if number < 0 or number > 3501:
            continue
        inputs.append(int(number))

for n in inputs:
    people = list(range(1, n+1))
    prime = 1
    i = -1
    for y in range(0, n-1):
        prime = get_next_prime(prime)
        i = i + prime if i + prime < n else (i + prime) % n
        people.pop(i)
        n -= 1
        i -= 1
    print("{}".format(people.pop()))