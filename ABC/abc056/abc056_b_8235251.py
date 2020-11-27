W,a,b = map(int, input().split())
if a>b:
  tmp = a
  a = b
  b = tmp
ans = b-(W+a)
print(ans if ans > 0 else 0)
  