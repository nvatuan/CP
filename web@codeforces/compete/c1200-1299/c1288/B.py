T = int(input())

def draft(B):
    if( len(str(B)) + 1 == len(str(B+1)) ): # 99..99 case
        return len(str(B))
    else:
        return len(str(B)) - 1

while T > 0:
    T -= 1
    ### ==================
    A, B = map(int, input().split())

    D = draft(B)
    print(A*D)