N = int(input())

ans = 0
for i in range(1,N+1):
  if (i&1)==0:
    continue
  t = 0
  for j in range(1, i+1):
    if (i%j)==0:
      t += 1
  if t == 8:
    ans += 1
    
print(ans)