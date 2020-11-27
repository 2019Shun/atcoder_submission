def w(p, c):
  return p // c

A,B,X = map(int, input().split())
print(w(B,X)-w(A-1, X))