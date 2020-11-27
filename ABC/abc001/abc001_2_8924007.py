km = int(input())/1000

if km < 0.1:
  print("00")
elif km <= 5:
  s = str(int(km*10))
  print(s.rjust(2, '0'))
elif km <= 30:
  print(str(int(km+50)))
elif km <= 70:
  print(str(int((km-30)/5+80)))
else:
  print("89")