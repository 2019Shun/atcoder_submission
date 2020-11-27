A,B,C,K = map(int, input().split())
S, T = map(int, input().split())

t = A*S + B*T
t -= C*(S+T) if (S+T)>=K else 0
print(t)