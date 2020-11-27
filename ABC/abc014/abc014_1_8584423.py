a = int(input())
b = int(input())
bn = b
while 1:
  if bn < a:
    bn += b
  else:
    print(bn-a)
    break