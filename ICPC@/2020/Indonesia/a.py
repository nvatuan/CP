f = open('test', 'w')
f.write(str(10**5))
f.write('\n')

n = 10**18
for i in range(10**5):
    f.write(str(n))
    f.write('\n')
