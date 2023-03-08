n = int(input())
numeros = input().split(" ")

soma = 0

for i in range(n):
    soma += int(numeros[i])

print(soma)
