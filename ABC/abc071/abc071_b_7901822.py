S=input()
s="abcdefghijklnmopqrstuvwxyz"
s = list(s)
  
for si in S:
  if si in s:
  	s.remove(si)
    
if s == []:
  print("None")
else:
  print(s[0])