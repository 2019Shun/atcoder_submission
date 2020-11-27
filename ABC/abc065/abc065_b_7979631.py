N = int(input())
a = []
for i in range(0, N):
  a.append(int(input()))
  a[i] -= 1;

ans = 1
n = 0
flag = 0
for i in range(0, N):
  if(a[n] == 1):
    flag = 1
    break
  else:
    ans += 1
    n = a[n]
if flag == 0:
  ans = -1
print(ans)