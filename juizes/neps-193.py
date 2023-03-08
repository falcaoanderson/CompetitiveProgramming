n, c = input().split()
n = int(n)
c = int(c)

if n>=c:
    print(int(n-c + (c*(c+1))/2))
else:
    print(int((c*(c+1))/2 - ((c-n)*(c-n+1))/2))
