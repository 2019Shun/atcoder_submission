N, M = map(int, input().split())
A = []
for i in range(N):
  A.append(list(map(int, input().split())))
         
ans = 0          
for i in range(M-1):
  for j in range(i+1, M):
    t = 0
    for k in range(N):
      t += max(A[k][i], A[k][j])
    ans = max(ans, t)
           
print(ans)           