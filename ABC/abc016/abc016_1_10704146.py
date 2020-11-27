M,D = map(int, input().split())
if(int(M/D*D) == int(M/D)*D):
  print("YES")
else:
  print("NO")