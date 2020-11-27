O = input()
E = input()

s = ""
for o,e in zip(O,E):
  s += o+e
if len(O) > len(E):
  s += O[-1]
if len(O) < len(E):
  s += E[-1]
print(s)