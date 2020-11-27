S = input()

def ok(s):
  n = len(s) 
  if n % 2 == 1:
    return False
  else:
	#print(s[0:n//2] + " " + s[n//2:])
    return s[0:n//2] == s[n//2:]

for i in range(1, len(S)+1):
  if ok(S[0:len(S)-i]):
    print(len(S)-i)
    break