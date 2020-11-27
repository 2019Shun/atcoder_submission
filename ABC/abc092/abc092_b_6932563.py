N = int(input())
D, X = map(int, input().split())
ans = 0
for i in range(N):
    a = int(input())
    ans += D//a
    if D%a!=0:
        ans+=1
print(ans + X)