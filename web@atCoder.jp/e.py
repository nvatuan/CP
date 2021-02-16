n = int(input())
a = list(map(int, input().split()))

xor_pair = []
for pair in range(0, n, 2):
    xor_pair.append(a[pair] ^ a[pair + 1])

xor_sum = 0
for xp in xor_pair:
    xor_sum ^= xp

ans = [xor_sum ^ neko for neko in a]
print(*ans)
