S = str(input())
if int(S) % 3 == 0:
  print(0)
  exit(0)
elif len(S) < 2:
    print(-1)
    exit(0)

sumdig = sum([int(i) for i in S])
S = ''.join([str(int(i) % 3) for i in S])

modulo = sumdig%3
if str(modulo) in S:
    print(1)
elif ((modulo == 2 and S.count('1') >= 2) or (modulo == 1 and S.count('2') >= 2)) and len(S) > 2:
    print(2)
else:
    print(-1)

