x,y = map(int, input().split())

if x == 2 or y == 2:
    print("No")
    exit()

a = [1,3,5,7,8,10,12]
b = [4,6,9,11]

if (x in a and y in a) or (x in b and y in b):
    print("Yes")
else:
    print("No")