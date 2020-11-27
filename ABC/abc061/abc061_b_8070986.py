N,M = map(int, input().split())
ans = [0]*N
for i in range(0, M):
  a, b = map(int, input().split())
  ans[a-1] += 1
  ans[b-1] += 1
for i in ans:
  print(i)