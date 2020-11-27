a = int(input())
b = int(input())
n = int(input())

def gcd(a,b):
  if b == 0:
    return a
  else:
    return gcd(b, a%b)
  
def lcm(a,b):
  return a * (b // gcd(a, b))

t = lcm(a,b)
ans = 0
while(1):
  if ans >= n:
    print(ans)
    exit()
  ans += t