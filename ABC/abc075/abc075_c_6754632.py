import queue

n, m = map(int, input().split())
ab = [[] for i in range(n)]
A = []
B = []

for i in range(m):
    a, b = map(int, input().split())
    a-=1
    b-=1
    ab[a].append(b)
    ab[b].append(a)
    A.append(a)
    B.append(b)

def bfs(ab, n, na, nb):
    ok = [False for i in range(n)]
    q = queue.Queue()
    q.put(0)
    while not q.empty():
        f = q.get()
        ok[f] = True
        for c in ab[f]:
            if (f==na and c==nb) or (f==nb and c==na):
                continue
            if ok[c] == False:
                q.put(c)
    
    flag = True
    for i in ok:
        flag &= i
    return flag

ans = 0
for a, b in zip(A, B):
    if bfs(ab, n, a, b) == False:
        ans += 1

print(ans)