def solve():
    x, n, m = map(int, input().split())

    while x > 0:
        if n > 0 and (x//2 + 10) < x:
            x = x//2 + 10
            n -= 1
            continue
        if m > 0:
            x -= 10
            m -= 1
            continue
        ## --
        print("NO");
        return
    
    print ("YES");
    return

if __name__ == "__main__":
    t = int(input())
    while t > 0:
        t -= 1
        solve();