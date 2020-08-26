def move(coor, char):
    if char == 'L':
        coor[0] -= 1
    if char == 'R':
        coor[0] += 1
    if char == 'D':
        coor[1] -= 1
    if char == 'U':
        coor[1] += 1
    return coor

def solve():
    N = int(input())
    cmd = input().strip()

    beenthere[ [0] * 
    coor = [0, 0]

    idx = 0

    beenthere[coor] = idx
    for c in cmd:
        coor = move(coor, c)
        beenthere[coor] = idx
    
    IDX = beenthere.get(coor, -1)
    if IDX == -1:
        print(IDX)
    else:
        print( *[IDX+1, len(cmd)] )


T = int(input())
while T > 0:
    T -= 1
    solve()
