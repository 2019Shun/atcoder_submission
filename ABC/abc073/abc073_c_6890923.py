N = int(input())
d = dict()

for i in range(N):
    a = str(input())
    if a in d:
        d[a] += 1
    else:
        d[a] = 1

ans = 0
for v in d.values():
    if (v & 1) == 1:
        ans += 1

print(ans)

