import math

N = int(input())
x = list(map(int, input().split()))

print(sum([abs(xi) for xi in x]))
print(math.sqrt(sum([abs(xi)**2 for xi in x])))
print(max([abs(xi) for xi in x]))