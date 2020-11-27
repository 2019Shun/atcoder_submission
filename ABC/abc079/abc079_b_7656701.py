N = int(input())
x = [2, 1]

for i in range(2, 87):
  x.append(x[i-1]+x[i-2])
  
print(x[N])