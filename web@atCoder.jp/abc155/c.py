V = {}
N = int(input())

MaxVote = 0
while N > 0:
    N -= 1
    ### 
    st = str(input())
    V[st] = V.get(st, 0)
    V[st] += 1
    MaxVote = max(MaxVote, V[st])

ans = []
for key, value in V.items():
    if value == MaxVote:
        ans.append(key)
ans.sort()
print(*ans, sep = '\n')
