val = int(input())

moedas = [100, 50, 25, 10, 5, 1]
qnt = [0, 0, 0, 0, 0, 0]

for i in range(len(moedas)):
    qnt[i] = val//moedas[i]
    val = val%moedas[i]

print(sum(qnt))
for i in qnt:
    print(i)
