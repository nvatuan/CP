st = input().strip().split('/')

ans = ''
for ss in st:
    if len(ss) > 0:
        ans += '/' + ss

if ans == '': print('/')
else: print(ans)
