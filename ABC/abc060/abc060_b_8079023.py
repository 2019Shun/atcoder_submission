A,B,C = map(int, input().split())

for i in range(0,B):
  if (A*(i+1)) % B == C:
    print("YES")
    exit()

print("NO")
