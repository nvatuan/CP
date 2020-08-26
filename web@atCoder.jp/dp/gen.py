f = open('in', 'w')

f.write('10000 9999\n')
for i in range(9999):
    f.write('%d %d\n' % (i + 1, i + 2))
f.close()