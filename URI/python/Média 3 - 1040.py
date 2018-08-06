n1, n2, n3, n4 = (round(float(x), 1) for x in input().split())
average = round((2 * n1 + 3 * n2 + 4 * n3 + n4) / 10, 1)
print("Media: {}".format(average))
if average >= 7:
    print("Aluno aprovado.")
elif average < 5:
    print("Aluno reprovado.")
elif average >= 5 and average <= 6.9:
    print("Aluno em exame.")
    exam = round(float(input()), 1)
    print("Nota do exame: {}".format(exam))
    average = (average + exam) / 2
    if average >= 5:
        print("Aluno aprovado.")
    elif average < 5:
        print("Aluno reprovado.")
    print("Media final: {}".format(average))