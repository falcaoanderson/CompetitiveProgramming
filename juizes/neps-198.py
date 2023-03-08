v = [[0 for y in range(3)] for x in range(3)]

for i in range(3):
    for j in range(3):
        v[i][j] = input()

for i in range(3):
    for j in range(3):
        print(v[i][j], end=" ")
    print()
    