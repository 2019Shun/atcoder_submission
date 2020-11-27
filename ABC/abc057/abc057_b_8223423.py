N, M = map(int, input().split())
s = []
for i in range(0, N):
  x, y = map(int, input().split())
  s.append([x, y])
ch = []
for i in range(0, M):
  x, y = map(int, input().split())
  ch.append([x, y])
  
for x,y in s:
  dist_min = 10000000000
  min_n = 0
  n = 0
  for c, d in ch:
    n += 1
    dist = abs(x-c)+ abs(y-d)
    if dist_min > dist:
      dist_min = dist
      min_n = n
  print(min_n)