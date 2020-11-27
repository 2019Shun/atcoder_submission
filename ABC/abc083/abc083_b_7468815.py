N, A, B = map(int, input().split())

def wa(n):
    w = 0
    while n != 0:
        w += n % 10
        n = int(n / 10)
    return w

ans = 0
for i in range(1, N+1):
    w = wa(i)
    if A <= w and w <= B:
        # print(i, w)
        ans += i

print(ans)
