def bin(s):
    b = '0b'
    for st in s:
            for c in st:
                    if c == '*':
                            b += '1'
                    else:
                            b += '0'
    
    return b

res = ''
t = 0

while True:
    IN = ''
    IN = input().strip()

    if IN == 'END':
        print(t, bin(res))
        res = ''
    elif IN == 'TERM':
        exit(0)
    else:
        res += IN
