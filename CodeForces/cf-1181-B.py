n = int(input())
s = input()

op1 = -1
op2 = -1

for i in range(n//2+1, n):
    if s[i]!='0':
        op1 = int(s[0:i]) + int(s[i:n])
        break
for i in range(n//2, 0, -1):
    if s[i]!='0':
        op2 = int(s[0:i]) + int(s[i:n])
        break

if op1==-1:
    print(op2)
elif op2==-1:
    print(op1)
elif op1<op2:
    print(op1)
else:
    print(op2)