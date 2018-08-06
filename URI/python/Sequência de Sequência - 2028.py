def count_sequence(number):
    if number is 0:
        return 1
    else:
        return count_sequence(number - 1) + number


case_count = 1
numbers = []
while True:
    try:
        read = input()
        if read is '':
            break
        numbers.append(read)
    except EOFError:
        break

for num in numbers:
    if num == '':
        break
    num = int(num)
    result = '0'
    for x in range(1, num+1):
        for y in range(0, x):
            result += ' ' + str(x)

    print("Caso {}: {} numero{}\n{}\n".format(case_count, count_sequence(num), ('s' if count_sequence(num) > 1 else ''), result))
    case_count += 1