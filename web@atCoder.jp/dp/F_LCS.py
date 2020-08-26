s = str(input())
t = str(input())

# pad a character to the first because i want to count index from 1
s = "." + s; t = "." + t;

a = len(s)
b = len(t)

dp = [['']*(b) for _ in range(2)]
# dp[i][j] is the length of lcs of s[0]s[1]...s[i] and t[0]t[1]...t[j]

for i in range(1, a):
    for j in range(1, b):
        if s[i] == t[j]:
            if len(dp[i&1][j]) < len(dp[(i+1)&1][j-1]) + 1:
                dp[i&1][j] = dp[(i+1)&1][j-1] + s[i]
        else:
            for adja in [[i-1, j-1], [i-1, j], [i, j-1]]:
                if len(dp[i&1][j]) < len(dp[adja[0]&1][adja[1]]):
                    dp[i&1][j] = dp[adja[0]&1][adja[1]]

print(dp[(a+1)&1][b-1])
