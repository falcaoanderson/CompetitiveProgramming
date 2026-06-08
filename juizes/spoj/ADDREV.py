# 19/01/26
n = int(input())

for i in range(n):
    a, b = input().split()

    a = a[::-1]
    b = b[::-1]

    resp = int(a) + int(b)
    resp = str(resp)

    print(int(resp[::-1]))