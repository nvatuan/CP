n = int(input())
s = str(input())

ans = s[::-1]
# print(ans)
print(len(s))

for i in range(1, n+1):
    part1 = s[:i]
    part2 = s[i:]
    # print(part1, part2)
    ans = min(
        ans,
        part1 + part2[::-1]
    )
print(ans)
