N = int(input())
A = map(int, input().split())

Ai = []

m  = 1000
for a in A:
    tmp = 0
    while(a % 2 == 0):
        tmp += 1
        a //= 2
    m = min(m, tmp)

print(m)
    