H, W = map(int, input().split())
v = []
for i in range(H):
  v += list(map(int, input().split()))
 
print(sum([max(0, vi-min(v)) for vi in v]))