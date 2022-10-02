primes = [2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97]

L, R = 0, len(primes)-1
q = 5

while q > 0:
  mid = (L+R+1)//2
  print('?', primes[mid])
  # print('?', primes[L:mid+1])
  tok = input().strip()
  if tok == '<':
    L = mid
  else:
    R = mid-1

  q -= 1

print('!', primes[L])
