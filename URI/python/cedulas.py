value = int(input())
c_100 = int(value/100)
c_50 = int((value%100)/50)
c_20 = int(((value%100)%50)/20)
c_10 = int((((value%100)%50)%20)/10)
c_5 = int(((((value%100)%50)%20)%10)/5)
c_2 = int((((((value%100)%50)%20)%10)%5)/2)
c_1 = int(((((((value%100)%50)%20)%10)%5)%2)/1)
print("{}\n{} nota(s) de R$ 100,00\n{} nota(s) de R$ 50,00\n{} nota(s) de R$ 20,00\n{} nota(s) de R$ 10,00\n{} nota(s) de R$ 5,00\n{} nota(s) de R$ 2,00\n{} nota(s) de R$ 1,00".format(value, c_100, c_50, c_20, c_10, c_5, c_2, c_1))