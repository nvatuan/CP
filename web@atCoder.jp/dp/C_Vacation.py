N = int(input())
a = [[0]*3 for ac in range(N)]

for i in range(N):
    a[i][0], a[i][1], a[i][2] = map(int, input().split())

dp = [[0]*3 for _ in range(N)]

dp[0][0] = a[0][0]
dp[0][1] = a[0][1]
dp[0][2] = a[0][2]

for i in range(1, N):
    for activity in range(3):
        for yesterday_activity in range(3):
            if yesterday_activity != activity:
                dp[i][activity] = max (
                    dp[i][activity], dp[i-1][yesterday_activity] + a[i][activity]
                )
print(max(dp[N-1][0], dp[N-1][1], dp[N-1][2]))