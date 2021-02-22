n = int(input())
a = list(map(int, input().split()))

prefix = [0]
for x in a:
    prefix.append(prefix[-1] + x)

prefix_max = [0]
for i in range(1, n+1):
    prefix_max.append(max(prefix_max[-1], prefix[i]))

#print(prefix)
#print(prefix_max)

ans = 0
curr = 0
for i in range(1, n+1):
    curr += prefix[i-1]
    ans = max(ans, curr + prefix_max[i])
print(ans)