N = int(input())
a = list(map(int, input().split()))

a.sort(reverse=True)

A = a[0:N:2]
B = a[1:N:2]

print(sum(A)-sum(B))