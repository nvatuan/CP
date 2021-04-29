def solve(x, param):
    a, b, c, d, e, f = param[:]
    if ( (e - a*x) % c == 0 ):
        if ( (f - b*x) % d == 0 ):
            if ((e-a*x)//c == (f-b*x)//d):
                y =  (e-a*x)//c
                if (y <= 0): return None
                return (x, (e-a*x)//c)
    return None

for tt in range(int(input())):
    a, b, c, d, e, f = map(int, input().split())
    param = [a, b, c, d, e, f]
    
    flag = 0
    root = None
    for x in range(1, 10**4+1):
        result = solve(x, param)
        if result is not None:
            flag += 1
            root = result
    if flag != 1:
        print('?')
    else:
        print(root[0], root[1])
    