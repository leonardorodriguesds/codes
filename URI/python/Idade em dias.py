while True:
    days = int(input())
    if days > 0:
        break

years = int(days / 365)
days = days % 365
months = int(days / 30)
days = int(days % 30)
print("{} ano(s)\n{} mes(es)\n{} dia(s)".format(years, months, days))