N=int(input())
S=input()
ans = 0
a = 0
for i in list(S):
  if i=="I":
    ans += 1
    a = max(ans, a)
  else:
    ans -= 1
    
print(a)