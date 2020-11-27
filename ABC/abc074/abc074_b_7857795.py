N = int(input())
K = int(input())
x = map(int, input().split())

ans = 0
for xi in x:
  ans += min(xi, abs(xi-K)) * 2
  
print(ans)