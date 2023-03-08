v = [int(x) for x in input().split()]

x = int(input())

resp = []

for i in range(len(v)):
    if v[i] == x:
        resp.append(i)

if len(resp)==0:
    print("Mia x")
else:
    print(len(resp))
    for i in resp:
        print(i, end=" ")