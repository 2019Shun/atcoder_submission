N = int(input())
A = map(int, input().split())

b2 = 0
b4 = 0
for a in A:
    if a % 2 == 0:
        b2 += 1

    if a % 4 == 0:
        b4 += 1

b2 -= b4

while b2 > 1:
    b2 -= 2
    # N -= 1
    b4 += 1

N -= b4*2+1

if N <= 0:
    print("Yes")
else:
    print("No")
    