import math
N = int(input())
ans = 0
for i in range(1, int(math.sqrt(N))+1):
  if(i == int(math.sqrt(i))*int(math.sqrt(i))):
    ans = i
    
print(i*i)