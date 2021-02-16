def solve():
    m = int(input())
    xs = 0
    for i in range(1, m): xs ^= i
    ans = [i for i in range(1, m+1) if i != xs]
    print(len(ans))
    print(*ans)

if __name__ == "__main__":
    t = int(input())
    for tt in range(t):
        solve()