import string

d = {}
for c in string.ascii_lowercase:
    d[c] = ord(c) - 95

def f(n):
    return (1 if n <= 1 else n*f(n-1))

def fhash(s):
    res = 1;
    for c in s:
        res *= f(d[c])
    return res

fa = fhash("h")
fb = fhash("abbf")
print(fa)
print(fb)

print("same hash" if fa == fb else "dif!")


a = []
dict = {}
llow = string.ascii_lowercase

temp = ['.'] * 95
def recur(num, depth):
    if num == 1:
        return 1
    #
    for i, hs in enumerate(a):
        if num % hs == 0:
            temp[depth] = llow[i]
            if recur(num // hs, depth + 1) == 1:
                return 1
    return 0
            

for c in string.ascii_lowercase:
    temp = []
    target = fhash(c);
    print(target)
    if recur(target, 0):
        dict[c] = temp
    else:
        dict[c] = c

    a.append(fhash(c))
    