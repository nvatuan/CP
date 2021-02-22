MOD = 10**9 + 7
dp = {0: 1}
 
S = int(input())
for s in range(3, S+1):
  for term in range(3, s+1):
    if s - term < 0:
      break
    else:
      dp[s] = dp.get(s-term, 0) + dp.get(s, 0) % MOD
 
print(dp.get(S, 0))
