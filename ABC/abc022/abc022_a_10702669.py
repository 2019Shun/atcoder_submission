N,S,T = map(int, input().split())
W = int(input())
ans = 0
for a in range(N-1):
  if S <= W <= T:
    ans +=1
  W += int(input())
if S <= W <= T:
  ans +=1
print(ans)