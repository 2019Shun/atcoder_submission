import sys
N = int(input())
H = map(int, input().split())

m = 0
for h in H:
    if m <= h-1 or m-1 <= h:
        m = max(m, h)
    else:
        print("No")
        sys.exit()

print("Yes")
        