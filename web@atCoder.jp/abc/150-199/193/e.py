n = int(input())
m = []
for i in range(n):
    m.append([x for x in input()])

print(m)

dp = [[[0]*2 for i in range(n)] for i2 in range(n)]

for i in range(n):
    for j in range(n):
        if i == 0 and j == 0:
            pass 
        elif i > 0 and j == 0:
            if m[i][j] in ['B', '?']:
                dp[i][j][0] = max(
                    dp[i][j][0],
                    dp[i-1][j][1] + 1, dp[i-1][j][0],
                )
            if m[i][j] in ['W', '?']:
                dp[i][j][1] = max(
                    dp[i][j][1],
                    dp[i-1][j][0] + 1, dp[i-1][j][1],
                )
        elif i == 0 and j > 0:
            if m[i][j] in ['B', '?']:
                dp[i][j][0] = max(
                    dp[i][j][0],
                    dp[i][j-1][1] + 1, dp[i][j-1][0]
                )
            if m[i][j] in ['W', '?']:
                dp[i][j][1] = max(
                    dp[i][j][1],
                    dp[i][j-1][0] + 1, dp[i][j-1][1]
                )
        else:
            if m[i][j] in ['B', '?']:
                if m[i-1][j] != 'B':
                    dp[i][j][0] = max(
                        dp[i][j][0],
                        max(dp[i-1][j][1] + 1, dp[i-1][j][0])+max(dp[i][j-1][1] + 1, dp[i][j-1][0])
                    )
                else:
                    dp[i][j][0] = max(
                        dp[i][j][0],
                        dp[i-1][j][0]
                    )
            if m[i][j] in ['W', '?']:
                if m[i][j-1] != 'W':
                dp[i][j][1] = max(
                    dp[i][j][1],
                    max(dp[i-1][j][0] + 1, dp[i-1][j][1])+max(dp[i][j-1][0] + 1, dp[i][j-1][1])
                )
            dp[i][j][0] -= max(dp[i-1][j-1][0], dp[i-1][j-1][1])
            dp[i][j][1] -= max(dp[i-1][j-1][0], dp[i-1][j-1][1])

for l in dp:
    print(l)
print(max(dp[n-1][n-1][0], dp[n-1][n-1][1]))