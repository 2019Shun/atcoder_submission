S = input()
s = []
for i in S:
  if i in ['a','i','u','e','o']:
    continue
  s.append(i)
  
print(''.join(s))