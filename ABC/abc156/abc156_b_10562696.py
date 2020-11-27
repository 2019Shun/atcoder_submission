N, K = map(int, input().split())

ans = 1
for i in range(100):
  if N >= K**(i):
    ans = i+1
print(ans)