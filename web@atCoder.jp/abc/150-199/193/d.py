k = int(input())
s = list([x for x in input()])
t = list([x for x in input()])

cnt = {}
for d in range(1, 10):
    cnt[d] = k

for x in s:
    if x != '#':
        cnt[int(x)] -= 1
for x in t:
    if x != '#':
        cnt[int(x)] -= 1

def scoring(st, missing):
    dcnt = [0] * 10
    for c in st:
        if c != '#':
            dcnt[int(c)] += 1
    dcnt[missing] += 1

    score = 0
    for d in range(1, 10):
        score += d * 10**dcnt[d]
    return score

win = 0
total = 0
for ds in range(1, 10):
    if cnt[ds] > 0:
        cnt[ds] -= 1

        for dt in range(1, 10):
            if cnt[dt] > 0:
                if scoring(s, ds) > scoring(t, dt):
                    win += (cnt[ds]+1)*(cnt[dt])
                total += (cnt[ds]+1)*(cnt[dt])

        cnt[ds] += 1

#print(win, total)
print(win/total)
