A, B, C, D = map(int, input().split())
ans = 0
for i in range(0, 101):
  if A <= i and i < B and C <= i and i < D:
    ans += 1
print(ans)