import string

offset = int(input())

H   = {}
rH  = {}

n = len(string.ascii_uppercase)
for i, c in enumerate(string.ascii_uppercase):
    H[c] = i
    rH[(i-offset+n) % n] = c

st = input().strip()
for c in st:
    print(rH[H[c]], end = '')