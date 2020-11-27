n = int(input())
a = list(map(int, input().split()))

if len(a) % 2 == 1:
  odd = a[1::2]
  even = a[-1::-2]
else:
  odd = a[::2]
  even = a[-1::-2]

for i in even + odd:
  print(i)