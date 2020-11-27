A = int(input())
B = int(input())
C = int(input())
a = [A,B,C]
b = sorted(a, reverse=True)
for i in range(3):
  for j in range(3):
    if b[j]==a[i]:
      print(j+1)
