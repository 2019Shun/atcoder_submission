N = int(input())
ans = 1
while 1:
  if ans * 2 <= N:
    ans *= 2
  else:
    break
print(ans)