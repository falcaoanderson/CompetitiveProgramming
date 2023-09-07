def solve(n):
    left = 2
    right = int(2e9)
    resp = 2

    while(left<=right):
        mid = (left+right)//2

        aux = (mid*(mid-1))//2 

        if aux == n:
            return mid
        elif aux > n:
            right = mid-1
        else:
            resp = max(resp, mid)
            left = mid+1
    return resp +  n - (resp*(resp-1))//2

t = int(input())
for i in range(t):
    n = int(input())

    print(solve(n))