A = int(input())

ans = 0
for a in range(A):
  ans = max(ans, a*(A-a))
print(ans)