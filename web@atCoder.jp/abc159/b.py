s = str(input())
mid = (len(s) + 1)//2

def palin(st):
    return st == st[::-1]

print('Yes' if palin(s[0:mid-1]) and palin(s[mid:]) and palin(s) else 'No')