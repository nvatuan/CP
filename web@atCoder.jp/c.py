from string import ascii_lowercase as asc_low

N = int(input())
name_length = 1
while 26**name_length < N:
  N -= (26**name_length)
  name_length += 1

##
N -= 1

table = {}
for i, c in enumerate(asc_low): table[i] = c

name = ['a']*name_length
for index in range(name_length):
  name[index] = table[(N % 26)]
  N //= 26
  if N == 0: break

print(*name[::-1], sep='')