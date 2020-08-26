__MULTITEST = True

def solve():
    s = str(input())
    i = 0
    n = len(s)

    turns = 0
    while n > 1:
        flag = False
        for i in range(1, n):
            if s[i-1] != s[i]:
                s = s[0:i-1] + s[i+1:]
                n -= 2
                turns +=1
                flag = True
                break
        if not flag:
            break

    print("DA" if turns % 2 == 1 else "NET")

# main
if __name__ == "__main__":
    t = (int(input()) if __MULTITEST else 1)
    for tt in range(t):
        solve()