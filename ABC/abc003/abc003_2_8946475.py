S = input()
T = input()

tmp = "atcoder"
flag = True
for s,t in zip(S,T):
  if s == "@" and t == "@":
    continue
  elif s == "@":
    if t in tmp:
      continue
  elif t == "@":
    if s in tmp:
      continue
  elif s == t:
    continue
  flag = False
  
print("You can win" if flag else "You will lose")
