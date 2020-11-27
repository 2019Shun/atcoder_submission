a,b = map(int, input().split())

#if (a*b)%2 != 1:
#  print("Even")
#else:
#  print("Odd")

if (a%2==0) or (b%2==0):
  print("Even")
else:
  print("Odd")