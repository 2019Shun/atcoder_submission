N = int(input())
A = list(map(int, input().split()))

f = True
for a in A:
  if (a&1)==0:
    if ((a%3==0) or (a%5==0)):
      pass
    else:
      f = False

if f:
  print("APPROVED")
else:
  print("DENIED")