T, A, K = map(int, input().split())

print(max(0, T-K), min(A, max(0, T+A-K)))