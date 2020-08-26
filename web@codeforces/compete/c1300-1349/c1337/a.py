def solve():
    a = list(map(int, input().split()))

    print(a[0], a[2], a[2]);


if __name__ == "__main__":
    t = int(input())
    while t > 0:
        t -= 1
        solve();