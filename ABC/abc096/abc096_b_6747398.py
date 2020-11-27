a = map(int, input().split())
k = int(input())

a = sorted(a, reverse=True)

print(a[0]*(1<<k)+a[1]+a[2])