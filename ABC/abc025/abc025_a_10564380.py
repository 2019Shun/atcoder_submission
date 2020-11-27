S = input()
N = int(input())
n = len(S)

print(S[(N-1)//n]+S[(N-1)%n])