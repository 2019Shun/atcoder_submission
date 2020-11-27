N = int(input())
K = int(input())

def dfs(rank, now):
  if rank == N:
    return now
  return min(dfs(rank+1, now*2), dfs(rank+1, now+K))

print(dfs(0,1))