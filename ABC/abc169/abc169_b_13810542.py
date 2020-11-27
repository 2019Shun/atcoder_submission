n = int(input())
a = list(map(int, input().split()))
tot = a[0]

if a.count(0) > 0:
  print(0)
  exit()

for i in range(1,n):
  if (tot > 1e18):
    print(-1)
    exit()
  tot *= a[i]
  
if (tot > 1e18):
  print(-1)
  exit()

print(tot)