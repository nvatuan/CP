n = int(input())

cnt = {}
hs = {}

for i in range(n):
    a = str(input()).split(' ')
    assert len(a) == 3

    if hs.get(tuple(a)) == None:
        hs[tuple(a)] = 1
        cnt[a[-1]] = cnt.get(a[-1], 0) + 1


for item in sorted(cnt.items()):
    print(item[0], item[1], end="")
    if (item[1] >= 10):
        print(" YES")
    else:
        print(" NO")

