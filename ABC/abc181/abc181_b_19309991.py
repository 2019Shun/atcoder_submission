N = int(input())
ans = 0
for i in range(N):
  a,b = map(int, input().split())
  ans += (b*(b+1)/2) - (a*(a-1)/2)
print(int(ans))