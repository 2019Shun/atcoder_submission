a,b = map(int, input().split())

c = int(str(a) + str(b))
import math
# print(c, math.sqrt(c))
if math.sqrt(c) == math.floor(math.sqrt(c)):
    print("Yes")
else:
    print("No")