a = list(input().split())
print(max(sum([ord(ai)-ord('0') for ai in a[0]]), sum([ord(ai)-ord('0') for ai in a[1]])))