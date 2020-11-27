N = int(input())
v = []
S = input().split()

for s in S:
    if not s in v:
        v.append(s);

if len(v) == 3:
    print("Three")
else:
    print("Four")