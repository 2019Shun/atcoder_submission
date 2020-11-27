A, B = map(int, input().split())
S = input()

if S[A] == '-' and S[0:A].isdigit() and S[A+1:A+B+1].isdigit():
  print("Yes")
else:
  print("No")