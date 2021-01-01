S = input()
n = len(S)

ans = 0

for i in range(n):
  for j in range(n-i):
    s = S[i:i+j+1]
    f = True
    for ts in s:
      if not (ts=='A' or ts=='C' or ts=='G' or ts=='T'):
        f = False
    if f:
      ans = max(ans, len(s))
      
print(ans)