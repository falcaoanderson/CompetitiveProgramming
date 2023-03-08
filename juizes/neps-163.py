n = int(input())
m = int(input())

v = set()

for i in range(m):
    v.add(input())

print(n-len(v))
