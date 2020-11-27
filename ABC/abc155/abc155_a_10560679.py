A, B, C = map(int, input().split())

if (A==B and B!=C) or (A==C and C!=B) or (C==B and B!=A):
  print('Yes')
else:
  print('No')