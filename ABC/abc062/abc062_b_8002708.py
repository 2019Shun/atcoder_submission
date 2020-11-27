H, W = map(int, input().split())

a = '#'*(W+2)

print(a)
for i in range(0,H):
  s = input()
  print('#'+s+'#')
print(a)
