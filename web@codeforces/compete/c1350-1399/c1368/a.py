__MULTITEST = 1

def solve():
    a, b, n = map(int, input().split())
    #
    if a > b:
        a, b = b, a
    
    ans1 = (n - a + 1)//b + (1 if (n - a + 1) % b != 0 else 0)
    
    ans2 = 0
    turn = 0
    while a <= n and b <= n:
        if a <= n and b <= n:
            if turn == 0:
                a += b
                turn += 1
            else:
                b += a
                turn -= 1
        ans2 += 1
    
    print(min(ans1, ans2))



####
if __name__ == "__main__":
    t = (int(input()) if __MULTITEST else 1)
    for tt in range(t):
        solve()