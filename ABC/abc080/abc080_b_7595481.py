N = int(input())

n = 0
t = N
while t != 0:
  n += t % 10
  t //= 10

if N % n == 0:
  print("Yes")
else:
  print("No")