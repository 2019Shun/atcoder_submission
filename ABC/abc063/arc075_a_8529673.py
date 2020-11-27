N=int(input())
a = []
for i in range(N):
  a.append(int(input()))
  
a.sort()
ans = sum(a)
for i in range(N):
  if ans % 10 == 0:
    ans -= a[0]
    for j in range(1,N):
      if ans % 10 == 0:
        ans += a[j-1]
        ans -= a[j]
      else:
        print(ans)
        exit(0)
    ans += a[N-1]
  else:
    print(ans)
    exit(0)
  ans -= a[i]
print(0)