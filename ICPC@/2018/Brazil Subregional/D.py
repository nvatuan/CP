N = int(input())

ans = 0
while N > 0:
    N -= 1
    i = int(input())
    ans += (i != 1)

print(ans)